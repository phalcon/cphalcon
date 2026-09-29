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
 * Scans the generated C (ext/phalcon/**\/*.zep.c) for the patterns of the optimization plan (strategy step 2) and
 * joins the findings to the scores of bin/rank.php (_scores.tsv, _helpers.tsv):
 * - C1: method calls by name with no cache (the cache arguments are "NULL, 0");
 * - C2: zephir_init_properties_* (property defaults set on each object creation);
 * - C3: a memory frame in a small method;
 * - C4: property array updates (read, separate and write back the property).
 *
 * Usage: php tests/benchmarks/bin/scan-c.php <scores-tsv> <helpers-tsv> <out-dir>
 *
 * Writes <out-dir>/c-findings.tsv and <out-dir>/c-report.md.
 */

use function Phalcon\Tests\Benchmarks\Bin\loadScores;
use function Phalcon\Tests\Benchmarks\Bin\rankFindings;
use function Phalcon\Tests\Benchmarks\Bin\scanReport;
use function Phalcon\Tests\Benchmarks\Bin\writeFindings;

require __DIR__ . '/lib/scan.php';

const ARRAY_UPDATES = [
    'zephir_update_property_array',
    'zephir_update_property_array_append',
    'zephir_update_property_array_multi',
    'zephir_unset_property_array',
];
const CALL_MACROS   = 'ZEPHIR_(?:RETURN_)?CALL_(?:METHOD|SELF|PARENT|CE_STATIC|FUNCTION)';
const HOT_RANK      = 50;
// Zephir generates these calls in each "for" loop over an untyped value. They run only for objects (Iterator),
// not for arrays.
const ITERATOR      = ['current', 'key', 'next', 'rewind', 'valid'];
const PATTERNS      = [
    'C1' => 'Method calls by name with no cache (`NULL, 0`)',
    'C2' => 'Property defaults set on each object creation',
    'C3' => 'Memory frame in a small method',
    'C4' => 'Property array updates',
];
const REGISTER      = '/ZEPHIR_REGISTER_(?:CLASS_EX|CLASS|INTERFACE_EX|INTERFACE)\(([\w\\\\]+),\s*(\w+),/';
const SMALL_METHOD  = 15;

if (4 !== $argc) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/scan-c.php <scores-tsv> <helpers-tsv> <out-dir>' . PHP_EOL);
    exit(2);
}

[, $scoresFile, $helpersFile, $out] = $argv;

foreach ([$scoresFile, $helpersFile] as $input) {
    if (!is_file($input)) {
        fwrite(STDERR, sprintf('Error: %s does not exist.', $input) . PHP_EOL);
        exit(1);
    }
}

$root   = dirname(__DIR__, 3);
$scores = loadScores($scoresFile);

$helpers = [];
foreach (array_slice(file($helpersFile, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES) ?: [], 1) as $line) {
    [$helper, $score, $ir, $calls] = explode("\t", $line);

    $helpers[$helper] = ['calls' => $calls, 'ir' => $ir, 'score' => $score];
}

$files = [];
foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($root . '/ext/phalcon')) as $item) {
    if ($item->isFile() && str_ends_with($item->getFilename(), '.zep.c')) {
        $files[] = $item->getPathname();
    }
}

sort($files);

/**
 * Returns the arguments of the call that starts after the "(" at $offset (commas inside parentheses, brackets
 * and strings do not split).
 */
$arguments = static function (string $text, int $offset): array {
    $arguments = [];
    $current   = '';
    $level     = 0;
    $quote     = null;
    $length    = strlen($text);
    for ($index = $offset; $index < $length; $index++) {
        $char = $text[$index];
        if (null !== $quote) {
            $current .= $char;
            if ('\\' === $char) {
                $current .= $text[++$index];
            } elseif ($char === $quote) {
                $quote = null;
            }

            continue;
        }

        if ('"' === $char || "'" === $char) {
            $quote = $char;
        } elseif ('(' === $char || '[' === $char) {
            $level++;
        } elseif (')' === $char || ']' === $char) {
            if (0 === $level) {
                $arguments[] = trim($current);

                return $arguments;
            }

            $level--;
        } elseif (',' === $char && 0 === $level) {
            $arguments[] = trim($current);
            $current     = '';
            continue;
        }

        $current .= $char;
    }

    return $arguments;
};

$findings = [];
$found    = [];
$macros   = [];

foreach ($files as $path) {
    $file  = substr($path, strlen($root) + 1);
    $lines = file($path, FILE_IGNORE_NEW_LINES) ?: [];
    $text  = implode("\n", $lines);

    if (preg_match_all('/\b(ZEPHIR_(?:RETURN_)?CALL_[A-Z_]+)\(/', $text, $matches)) {
        foreach ($matches[1] as $macro) {
            $macros[$macro] = ($macros[$macro] ?? 0) + 1;
        }
    }

    $class = '';
    if (1 === preg_match(REGISTER, $text, $matches)) {
        $class = str_replace('\\\\', '\\', $matches[1]) . '\\' . $matches[2];
    }

    /**
     * Blocks: PHP_METHOD(...) and zephir_init_properties_*(), each to the next top-level definition.
     */
    $blocks = [];
    $block  = null;
    foreach ($lines as $index => $line) {
        $method     = 1 === preg_match('/^PHP_METHOD\(\w+,\s*(\w+)\)/', $line, $methodMatch);
        $properties = 1 === preg_match('/^zend_object \*(zephir_init_properties_\w+)\(/', $line, $propertiesMatch);
        $other      = 1 === preg_match('/^(static |ZEPHIR_INIT_CLASS|void |int |zend_object )/', $line);

        if ($method || $properties || $other) {
            if (null !== $block) {
                $blocks[] = $block;
                $block    = null;
            }

            if ($method) {
                $block = ['kind' => 'method', 'line' => $index + 1, 'lines' => [], 'name' => $methodMatch[1]];
            } elseif ($properties) {
                $block = ['kind' => 'properties', 'line' => $index + 1, 'lines' => [], 'name' => $propertiesMatch[1]];
            }
        }

        if (null !== $block) {
            $block['lines'][] = $line;
        }
    }

    if (null !== $block) {
        $blocks[] = $block;
    }

    foreach ($blocks as $block) {
        $body = implode("\n", $block['lines']);
        $key  = $class . '::' . ('method' === $block['kind'] ? $block['name'] : '(init properties)');
        $add  = static function (string $pattern, string $text) use (&$findings, $file, $block, $key): void {
            $findings[] = [
                'file'    => $file,
                'line'    => $block['line'],
                'method'  => $key,
                'pattern' => $pattern,
                'text'    => $text,
            ];
        };

        $frame = 1 === preg_match('/zephir_memory_grow_stack\(|ZEPHIR_MM_GROW\(\)/', $body);

        if ('properties' === $block['kind']) {
            preg_match_all('/zephir_update_property_zval_ex\(this_ptr, ZEND_STRL\("(\w+)"\)/', $body, $matches);
            $helper = $helpers[$block['name']] ?? null;
            $usage  = '; not called in the apps';
            if (null !== $helper) {
                $usage = '; apps: calls ' . $helper['calls'] . ', Ir ' . $helper['ir']
                    . ', score ' . $helper['score'] . '%';
            }

            $add(
                'C2',
                count($matches[1]) . ' properties (' . implode(', ', $matches[1]) . ')'
                . ($frame ? '; memory frame' : '') . $usage
            );
            continue;
        }

        $found[strtolower($key)] = true;

        // C1: calls by name, with the cache arguments after the name
        $total   = 0;
        $noCache = [];
        if (preg_match_all('/\b(' . CALL_MACROS . ')\(/', $body, $matches, PREG_OFFSET_CAPTURE)) {
            foreach ($matches[0] as $match) {
                $callArguments = $arguments($body, $match[1] + strlen($match[0]));
                foreach ($callArguments as $position => $argument) {
                    if (1 === preg_match('/^"(\w+)"$/', $argument, $name)) {
                        $total++;
                        $cache = $callArguments[$position + 1] ?? '';
                        $slot  = $callArguments[$position + 2] ?? '';
                        if ('NULL' === $cache && '0' === $slot) {
                            $noCache[$name[1]] = ($noCache[$name[1]] ?? 0) + 1;
                        }

                        break;
                    }
                }
            }
        }

        $iterator = 0;
        foreach (ITERATOR as $name) {
            $iterator += $noCache[$name] ?? 0;
            unset($noCache[$name]);
        }

        if ([] !== $noCache) {
            arsort($noCache);

            $names = [];
            foreach ($noCache as $name => $count) {
                $names[] = $name . ($count > 1 ? ' x' . $count : '');
            }

            $add(
                'C1',
                array_sum($noCache) . ' of ' . $total . ' calls; iterator loop code ' . $iterator . ': '
                . implode(', ', $names)
            );
        }

        // C3: memory frame in a small method (the lines after the frame starts)
        if ($frame) {
            $after = preg_split('/zephir_memory_grow_stack\([^;]*;|ZEPHIR_MM_GROW\(\);/', $body, 2)[1] ?? '';
            $count = 0;
            foreach (explode("\n", $after) as $line) {
                if ('' !== trim($line) && '}' !== trim($line) && '{' !== trim($line)) {
                    $count++;
                }
            }

            if ($count <= SMALL_METHOD) {
                $add('C3', $count . ' lines after the memory frame starts');
            }
        }

        // C4: property array updates
        $updates = [];
        foreach (ARRAY_UPDATES as $function) {
            $count = preg_match_all('/\b' . $function . '\(/', $body);
            if ($count > 0) {
                $updates[] = $function . ' x' . $count;
            }
        }

        if ([] !== $updates) {
            $add('C4', implode(', ', $updates));
        }
    }
}

if (!is_dir($out)) {
    mkdir($out, 0777, true);
}

$ranked = rankFindings($findings, $scores);
writeFindings($ranked, $out . '/c-findings.tsv');

ksort($macros);

$report  = scanReport('Static scan: generated C', $ranked, $scores, $found, PATTERNS, HOT_RANK);
$report .= PHP_EOL . '## Call macros (all files)' . PHP_EOL . PHP_EOL;
$report .= '| Macro | Count |' . PHP_EOL . '|---|---:|' . PHP_EOL;
foreach ($macros as $macro => $count) {
    $report .= '| `' . $macro . '` | ' . $count . ' |' . PHP_EOL;
}

file_put_contents($out . '/c-report.md', $report);

echo 'Files: ', count($files), '; methods: ', count($found), '; findings: ', count($ranked), PHP_EOL;
foreach ($macros as $macro => $count) {
    echo $macro, ' ', $count, PHP_EOL;
}
echo 'Report: ', $out, '/c-report.md', PHP_EOL;
