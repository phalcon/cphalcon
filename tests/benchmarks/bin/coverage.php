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
 * Reads the callgrind files of one subject (0, 1 and 1+k calls) and prints a coverage report (markdown):
 * calls, self Ir and inclusive Ir of each function, for the first call (cold) and for one later call (warm).
 * It also writes a TSV file with the first-level components.
 *
 * Usage: php tests/benchmarks/bin/coverage.php <file-0> <file-1> <file-1k> <k> <title> <tsv-file>
 *
 * Run it with the Phalcon extension loaded (bin/php-bench). It maps the Zephir method symbols
 * (zim_Phalcon_...) to Class::method with reflection.
 */

if (7 !== $argc || !ctype_digit($argv[4]) || 1 > (int) $argv[4]) {
    fwrite(
        STDERR,
        'Usage: php tests/benchmarks/bin/coverage.php <file-0> <file-1> <file-1k> <k> <title> <tsv-file>' . PHP_EOL
    );
    exit(2);
}

[, $fileZero, $fileOne, $fileMany, $k, $title, $tsvFile] = $argv;

$k = (int) $k;

/**
 * Reads one callgrind file. Returns the self Ir, the inclusive Ir and the calls of each function, and the
 * total Ir of the run.
 */
$parse = static function (string $file): array {
    $handle = fopen($file, 'rb');
    if (false === $handle) {
        throw new RuntimeException('Cannot open ' . $file);
    }

    $names = [];

    /**
     * A name is "(id) name" the first time, and "(id)" after that.
     */
    $resolve = static function (string $value) use (&$names): string {
        if (1 !== preg_match('/^\((\d+)\)(?: (.+))?$/', $value, $matches)) {
            return $value;
        }

        if (isset($matches[2])) {
            $names[$matches[1]] = $matches[2];
        }

        return $names[$matches[1]] ?? $value;
    };

    $cost = static function (string $line): int {
        $fields = explode(' ', trim($line));

        return count($fields) > 1 ? (int) end($fields) : 0;
    };

    $self       = [];
    $callCost   = [];
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
         * The line after "calls=" is the inclusive cost of those calls.
         */
        if ($isCallCost) {
            $callCost[$current] = ($callCost[$current] ?? 0) + $cost($line);
            $isCallCost         = false;
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
     * Check: the self Ir of all functions is the total Ir of the run.
     */
    if (array_sum($self) !== $total) {
        throw new RuntimeException(
            sprintf('Parser check failed for %s: self Ir sum %d, summary %d', $file, array_sum($self), $total)
        );
    }

    $inclusive = $self;
    foreach ($callCost as $function => $value) {
        $inclusive[$function] = ($inclusive[$function] ?? 0) + $value;
    }

    return [
        'calls'     => $calls,
        'inclusive' => $inclusive,
        'self'      => $self,
        'total'     => $total,
    ];
};

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
 * Returns the group (phalcon, zephir, other), the display name and the two component levels of a symbol.
 */
$describe = static function (string $symbol) use ($methods): array {
    // The compiler can add a suffix (".part.0", ".lto_priv.0"). Callgrind adds "'2", "'3" for recursion levels.
    $base = (string) preg_replace("/'\d+$/", '', explode('.', $symbol, 2)[0]);

    if (isset($methods[$base])) {
        $name   = $methods[$base];
        $parts  = explode('\\', substr($name, 0, (int) strpos($name, '::')));
        $first  = $parts[1];
        $second = isset($parts[2]) ? $first . '\\' . $parts[2] : $first;

        return ['phalcon', $name, $first, $second];
    }

    if (str_starts_with($base, 'zephir_')) {
        return ['zephir', $base, '', ''];
    }

    return ['other', $base, '', ''];
};

$runs = [$parse($fileZero), $parse($fileOne), $parse($fileMany)];

$coldTotal = $runs[1]['total'] - $runs[0]['total'];
$warmTotal = ($runs[2]['total'] - $runs[1]['total']) / $k;

/**
 * Cold and warm values of each function. Functions with the same display name are added together.
 */
$rows    = [];
$symbols = [];
foreach ($runs as $run) {
    $symbols += array_flip(array_keys($run['self'] + $run['inclusive'] + $run['calls']));
}

foreach (array_keys($symbols) as $symbol) {
    $symbol                          = (string) $symbol;
    [$group, $name, $first, $second] = $describe($symbol);
    $row                             = $rows[$group . '|' . $name] ?? [
        'group'          => $group,
        'name'           => $name,
        'first'          => $first,
        'second'         => $second,
        'calls_cold'     => 0,
        'calls_warm'     => 0.0,
        'self_cold'      => 0,
        'self_warm'      => 0.0,
        'inclusive_cold' => 0,
        'inclusive_warm' => 0.0,
    ];

    foreach (['calls', 'self', 'inclusive'] as $metric) {
        $zero = $runs[0][$metric][$symbol] ?? 0;
        $one  = $runs[1][$metric][$symbol] ?? 0;
        $many = $runs[2][$metric][$symbol] ?? 0;

        $row[$metric . '_cold'] += $one - $zero;
        $row[$metric . '_warm'] += ($many - $one) / $k;
    }

    $rows[$group . '|' . $name] = $row;
}

$rows = array_filter(
    $rows,
    static function (array $row): bool {
        return 0 !== $row['calls_cold'] || abs($row['calls_warm']) >= 0.05
            || 0 !== $row['self_cold'] || abs($row['self_warm']) >= 0.5;
    }
);

$number = static function (float | int $value, int $decimals = 0): string {
    return number_format($value, $decimals, '.', ',');
};

$share = static function (float | int $value, float | int $total): string {
    return 0 == $total ? '-' : number_format(100 * $value / $total, 1) . '%';
};

/**
 * Sums the self Ir and the calls of the rows by a key.
 */
$sum = static function (array $rows, string $key): array {
    $sums = [];
    foreach ($rows as $row) {
        $name        = $row[$key];
        $sums[$name] = $sums[$name] ?? [
            'calls_cold' => 0,
            'calls_warm' => 0.0,
            'methods'    => 0,
            'self_cold'  => 0,
            'self_warm'  => 0.0,
        ];

        $sums[$name]['calls_cold'] += $row['calls_cold'];
        $sums[$name]['calls_warm'] += $row['calls_warm'];
        $sums[$name]['methods']++;
        $sums[$name]['self_cold'] += $row['self_cold'];
        $sums[$name]['self_warm'] += $row['self_warm'];
    }

    uasort(
        $sums,
        static function (array $left, array $right): int {
            return $right['self_cold'] <=> $left['self_cold'];
        }
    );

    return $sums;
};

$top = static function (array $rows, string $group, string $sortKey, int $limit): array {
    $selected = array_filter(
        $rows,
        static function (array $row) use ($group): bool {
            return $group === $row['group'];
        }
    );

    uasort(
        $selected,
        static function (array $left, array $right) use ($sortKey): int {
            return $right[$sortKey] <=> $left[$sortKey];
        }
    );

    return array_slice($selected, 0, $limit);
};

$groups   = $sum($rows, 'group');
$phalcon  = array_filter(
    $rows,
    static function (array $row): bool {
        return 'phalcon' === $row['group'];
    }
);
$firsts   = $sum($phalcon, 'first');
$seconds  = $sum($phalcon, 'second');

$lines   = [];
$lines[] = '# Coverage: ' . $title;
$lines[] = '';
$lines[] = '- cold: the first call (Ir of 1 call minus Ir of 0 calls).';
$lines[] = '- warm: one later call ((Ir of 1+k calls minus Ir of 1 call) / k).';
$lines[] = '- self Ir: instructions in the function itself. Inclusive Ir: with the functions it calls'
    . ' (recursive functions count some cost twice).';
$lines[] = '';
$lines[] = '| Request | Total Ir | Phalcon methods (self) | zephir_* helpers (self) | Other (self) |';
$lines[] = '|---|---:|---:|---:|---:|';
foreach (['cold' => $coldTotal, 'warm' => $warmTotal] as $request => $total) {
    $cells = [];
    foreach (['phalcon', 'zephir', 'other'] as $group) {
        $value   = $groups[$group]['self_' . $request] ?? 0;
        $cells[] = $number($value) . ' (' . $share($value, $total) . ')';
    }
    $lines[] = '| ' . $request . ' | ' . $number($total) . ' | ' . implode(' | ', $cells) . ' |';
}

foreach (['first level' => $firsts, 'second level' => $seconds] as $level => $components) {
    $lines[] = '';
    $lines[] = '## Components (' . $level . ', self Ir of Phalcon methods)';
    $lines[] = '';
    $lines[] = '| Component | Methods | Calls cold | Calls warm | Self Ir cold | Cold % | Self Ir warm | Warm % |';
    $lines[] = '|---|---:|---:|---:|---:|---:|---:|---:|';
    foreach ($components as $component => $values) {
        $lines[] = '| ' . $component
            . ' | ' . $values['methods']
            . ' | ' . $number($values['calls_cold'])
            . ' | ' . $number($values['calls_warm'], 1)
            . ' | ' . $number($values['self_cold'])
            . ' | ' . $share($values['self_cold'], $coldTotal)
            . ' | ' . $number($values['self_warm'])
            . ' | ' . $share($values['self_warm'], $warmTotal) . ' |';
    }
}

$lines[] = '';
$lines[] = '## Top 40 Phalcon methods (by inclusive Ir cold)';
$lines[] = '';
$lines[] = '| Method | Calls cold | Calls warm | Self cold | Self warm | Inclusive cold | Inclusive warm |';
$lines[] = '|---|---:|---:|---:|---:|---:|---:|';
foreach ($top($rows, 'phalcon', 'inclusive_cold', 40) as $row) {
    $lines[] = '| `' . $row['name'] . '`'
        . ' | ' . $number($row['calls_cold'])
        . ' | ' . $number($row['calls_warm'], 1)
        . ' | ' . $number($row['self_cold'])
        . ' | ' . $number($row['self_warm'])
        . ' | ' . $number($row['inclusive_cold'])
        . ' | ' . $number($row['inclusive_warm']) . ' |';
}

foreach (['zephir' => ['Top 20 zephir_* helpers', 20], 'other' => ['Top 15 other functions', 15]] as $group => $setup) {
    $lines[] = '';
    $lines[] = '## ' . $setup[0] . ' (by self Ir cold)';
    $lines[] = '';
    $lines[] = '| Function | Calls cold | Calls warm | Self cold | Self warm |';
    $lines[] = '|---|---:|---:|---:|---:|';
    foreach ($top($rows, $group, 'self_cold', $setup[1]) as $row) {
        $lines[] = '| `' . $row['name'] . '`'
            . ' | ' . $number($row['calls_cold'])
            . ' | ' . $number($row['calls_warm'], 1)
            . ' | ' . $number($row['self_cold'])
            . ' | ' . $number($row['self_warm']) . ' |';
    }
}

echo implode(PHP_EOL, $lines), PHP_EOL;

$tsv = ["component\tself_cold\tself_warm", "_total\t" . $coldTotal . "\t" . round($warmTotal)];
foreach ($firsts as $component => $values) {
    $tsv[] = $component . "\t" . $values['self_cold'] . "\t" . round($values['self_warm']);
}
file_put_contents($tsvFile, implode(PHP_EOL, $tsv) . PHP_EOL);
