<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

/**
 * Reads the callgrind files of one subject (1 and 1+k calls, with caller chains) and prints the own cost of
 * each Phalcon method for one warm call (markdown). It also writes a TSV file with one row for each owner and
 * helper.
 *
 * The owner of a cost is the nearest of these in its chain (the function, then its callers):
 * - a Phalcon function (zim_*, zep_*); it owns its self Ir (helper "(self)") and the Ir of the functions that
 *   it calls;
 * - execute_ex (PHP code runs): "(userland)";
 * - php_request_shutdown (objects freed at the end of the request): "(shutdown)";
 * - zend_gc_collect_cycles (the garbage collector): "(gc)".
 * A chain with none of these is "(unattributed)".
 *
 * Usage: php tests/benchmarks/bin/attribute.php <file-1> <file-1k> <k> <title> <tsv-file>
 *
 * Run it with the Phalcon extension loaded (bin/php-bench). It maps the Zephir method symbols
 * (zim_Phalcon_...) to Class::method with reflection.
 */

if (6 !== $argc || !ctype_digit($argv[3]) || 1 > (int) $argv[3]) {
    fwrite(
        STDERR,
        'Usage: php tests/benchmarks/bin/attribute.php <file-1> <file-1k> <k> <title> <tsv-file>' . PHP_EOL
    );
    exit(2);
}

[, $fileOne, $fileMany, $k, $title, $tsvFile] = $argv;

$k = (int) $k;

/**
 * Map of Zephir method symbols to Class::method, from reflection of the phalcon extension.
 */
$methods = [];
foreach (get_declared_classes() as $class) {
    if (!str_starts_with($class, 'Phalcon\\')) {
        continue;
    }

    $reflection = new ReflectionClass($class);
    if ('phalcon' !== $reflection->getExtensionName()) {
        continue;
    }

    foreach ($reflection->getMethods() as $method) {
        if ($method->class === $class) {
            $methods['zim_' . str_replace('\\', '_', $class) . '_' . $method->name] = $class . '::' . $method->name;
        }
    }
}

/**
 * Returns the owner and the helper of a context "function'caller1'caller2...".
 */
$attribute = static function (string $context) use ($methods): array {
    $chain = [];
    foreach (explode("'", $context) as $part) {
        // Parts with digits only are recursion levels. The compiler can add a suffix (".part.0").
        if ('' === $part || ctype_digit($part)) {
            continue;
        }

        $chain[] = explode('.', $part, 2)[0];
    }

    // Engine functions that stop the search: PHP code, the garbage collector, the end of the request.
    $markers = [
        'execute_ex'             => '(userland)',
        'php_request_shutdown'   => '(shutdown)',
        'zend_gc_collect_cycles' => '(gc)',
    ];

    $function = $chain[0] ?? '';
    $helper   = str_starts_with($function, '0x') ? '(unnamed)' : $function;
    foreach ($chain as $index => $symbol) {
        if (str_starts_with($symbol, 'zim_') || str_starts_with($symbol, 'zep_')) {
            return [$methods[$symbol] ?? $symbol, 0 === $index ? '(self)' : $helper];
        }

        if (isset($markers[$symbol])) {
            return [$markers[$symbol], $helper];
        }
    }

    return ['(unattributed)', $helper];
};

/**
 * Reads one callgrind file. Returns the self Ir and the calls for each "owner|helper" key, and the total Ir.
 */
$parse = static function (string $file) use ($attribute): array {
    $handle = fopen($file, 'rb');
    if (false === $handle) {
        throw new RuntimeException('Cannot open ' . $file);
    }

    $names = [];
    $keys  = [];

    /**
     * A name is "(id) name" the first time, and "(id)" after that. Returns the "owner|helper" key.
     */
    $resolve = static function (string $value) use (&$names, &$keys, $attribute): string {
        if (1 === preg_match('/^\((\d+)\)(?: (.+))?$/', $value, $matches)) {
            if (isset($matches[2])) {
                $names[$matches[1]] = $matches[2];
            }

            $value = $names[$matches[1]] ?? $value;
        }

        if (!isset($keys[$value])) {
            $keys[$value] = implode('|', $attribute($value));
        }

        return $keys[$value];
    };

    $cost = static function (string $line): int {
        $fields = explode(' ', trim($line));

        return count($fields) > 1 ? (int) end($fields) : 0;
    };

    $self       = [];
    $calls      = [];
    $total      = 0;
    $current    = '';
    $callee     = '';
    $isCallCost = false;

    while (false !== ($line = fgets($handle))) {
        $line = rtrim($line, "\n");
        if ('' === $line) {
            continue;
        }

        /**
         * The line after "calls=" is the inclusive cost of those calls. It is not self cost.
         */
        if ($isCallCost) {
            $isCallCost = false;
            continue;
        }

        if (1 === preg_match('/^[0-9+*-]/', $line)) {
            $self[$current] = ($self[$current] ?? 0) + $cost($line);
            continue;
        }

        if (str_starts_with($line, 'fn=')) {
            $current = $resolve(substr($line, 3));
        } elseif (str_starts_with($line, 'cfn=')) {
            $callee = $resolve(substr($line, 4));
        } elseif (str_starts_with($line, 'calls=')) {
            $calls[$callee] = ($calls[$callee] ?? 0) + (int) substr($line, 6);
            $isCallCost     = true;
        } elseif (str_starts_with($line, 'summary: ')) {
            $total = (int) substr($line, 9);
        }
    }

    fclose($handle);

    /**
     * Check: the self Ir of all contexts is the total Ir of the run.
     */
    if (array_sum($self) !== $total) {
        throw new RuntimeException(
            sprintf('Parser check failed for %s: self Ir sum %d, summary %d', $file, array_sum($self), $total)
        );
    }

    return [
        'calls' => $calls,
        'self'  => $self,
        'total' => $total,
    ];
};

$one  = $parse($fileOne);
$many = $parse($fileMany);

$warmTotal = ($many['total'] - $one['total']) / $k;

/**
 * Warm values for each "owner|helper" key.
 */
$rows = [];
foreach (array_keys($one['self'] + $one['calls'] + $many['self'] + $many['calls']) as $key) {
    $key              = (string) $key;
    [$owner, $helper] = explode('|', $key, 2);
    $calls            = (($many['calls'][$key] ?? 0) - ($one['calls'][$key] ?? 0)) / $k;
    $self             = (($many['self'][$key] ?? 0) - ($one['self'][$key] ?? 0)) / $k;
    if (0.0 === (float) $calls && 0.0 === (float) $self) {
        continue;
    }

    $rows[] = [
        'calls'  => $calls,
        'helper' => $helper,
        'owner'  => $owner,
        'self'   => $self,
    ];
}

/**
 * Own cost for each owner, and cost for each helper.
 */
$owners  = [];
$helpers = [];
foreach ($rows as $row) {
    $owner  = $row['owner'];
    $helper = $row['helper'];

    $owners[$owner] = $owners[$owner] ?? ['calls' => 0.0, 'helpers' => [], 'own' => 0.0, 'self' => 0.0];
    $owners[$owner]['own'] += $row['self'];
    if ('(self)' === $helper) {
        $owners[$owner]['calls'] += $row['calls'];
        $owners[$owner]['self']  += $row['self'];
    } else {
        $owners[$owner]['helpers'][$helper] = ['calls' => $row['calls'], 'self' => $row['self']];

        $helpers[$helper] = $helpers[$helper] ?? ['calls' => 0.0, 'owners' => [], 'self' => 0.0];
        $helpers[$helper]['calls']         += $row['calls'];
        $helpers[$helper]['self']          += $row['self'];
        $helpers[$helper]['owners'][$owner] = $row['self'];
    }
}

$bySelf = static function (array $left, array $right): int {
    return $right['self'] <=> $left['self'];
};

uasort(
    $owners,
    static function (array $left, array $right): int {
        return $right['own'] <=> $left['own'];
    }
);
uasort($helpers, $bySelf);

$number = static function (float | int $value, int $decimals = 0): string {
    return number_format($value, $decimals, '.', ',');
};

$share = static function (float | int $value) use ($warmTotal): string {
    return 0 == $warmTotal ? '-' : number_format(100 * $value / $warmTotal, 1) . '%';
};

/**
 * Returns the <limit> largest entries of a name => value list as "name value" text.
 */
$largest = static function (array $values, int $limit, callable $format): string {
    arsort($values);

    $parts = [];
    foreach (array_slice($values, 0, $limit, true) as $name => $value) {
        $parts[] = $format((string) $name, $value);
    }

    return implode('; ', $parts);
};

$phalconOwn = 0.0;
foreach ($owners as $owner => $values) {
    if (!str_starts_with((string) $owner, '(')) {
        $phalconOwn += $values['own'];
    }
}

$lines   = [];
$lines[] = '# Own cost: ' . $title;
$lines[] = '';
$lines[] = '- warm: one later call ((Ir of 1+k calls minus Ir of 1 call) / k).';
$lines[] = '- own Ir: the self Ir of a Phalcon method plus the helpers and engine functions that it calls,'
    . ' without the Phalcon methods and the userland code that it calls.';
$lines[] = '';

$cells = [$number($warmTotal), $number($phalconOwn) . ' (' . $share($phalconOwn) . ')'];
foreach (['(userland)', '(shutdown)', '(gc)', '(unattributed)'] as $owner) {
    $own     = $owners[$owner]['own'] ?? 0;
    $cells[] = $number($own) . ' (' . $share($own) . ')';
}

$lines[] = '| Warm total Ir | Phalcon owners | (userland) | (shutdown) | (gc) | (unattributed) |';
$lines[] = '|---:|---:|---:|---:|---:|---:|';
$lines[] = '| ' . implode(' | ', $cells) . ' |';

$lines[] = '';
$lines[] = '## Top 40 owners (by own Ir)';
$lines[] = '';
$lines[] = '| Owner | Own Ir | Share | Self Ir | Calls | Top helpers (Ir, calls) |';
$lines[] = '|---|---:|---:|---:|---:|---|';
foreach (array_slice($owners, 0, 40, true) as $owner => $values) {
    $helperCost = [];
    foreach ($values['helpers'] as $helper => $helperValues) {
        $helperCost[$helper] = $helperValues['self'];
    }

    $lines[] = '| `' . $owner . '`'
        . ' | ' . $number($values['own'])
        . ' | ' . $share($values['own'])
        . ' | ' . $number($values['self'])
        . ' | ' . $number($values['calls'], 1)
        . ' | ' . $largest(
            $helperCost,
            3,
            static function (string $name, float $value) use ($number, $values): string {
                return '`' . $name . '` ' . $number($value) . ', ' . $number($values['helpers'][$name]['calls'], 1);
            }
        ) . ' |';
}

$lines[] = '';
$lines[] = '## Top 20 helpers (by Ir)';
$lines[] = '';
$lines[] = '| Helper | Ir | Share | Calls | Top owners (Ir) |';
$lines[] = '|---|---:|---:|---:|---|';
foreach (array_slice($helpers, 0, 20, true) as $helper => $values) {
    $lines[] = '| `' . $helper . '`'
        . ' | ' . $number($values['self'])
        . ' | ' . $share($values['self'])
        . ' | ' . $number($values['calls'], 1)
        . ' | ' . $largest(
            $values['owners'],
            3,
            static function (string $name, float $value) use ($number): string {
                return '`' . $name . '` ' . $number($value);
            }
        ) . ' |';
}

echo implode(PHP_EOL, $lines), PHP_EOL;

$tsv = ["owner\thelper\tcalls_warm\tself_warm", "_total\t-\t0\t" . round($warmTotal, 1)];
foreach ($rows as $row) {
    $tsv[] = $row['owner'] . "\t" . $row['helper'] . "\t" . round($row['calls'], 2) . "\t" . round($row['self'], 2);
}
file_put_contents($tsvFile, implode(PHP_EOL, $tsv) . PHP_EOL);
