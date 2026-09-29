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
 * Scans the Zephir source (phalcon/**\/*.zep) for the code patterns of the optimization plan (section B) and joins
 * the findings to the scores of bin/rank.php (_scores.tsv).
 *
 * The scanner is line-based. It finds the methods and the loops with a brace counter that ignores comments and
 * the text in string literals. The patterns are regular expressions, so a finding is a candidate: read the source
 * before a change.
 *
 * Usage: php tests/benchmarks/bin/scan-zep.php <scores-tsv> <out-dir>
 *
 * Writes <out-dir>/zep-findings.tsv and <out-dir>/zep-report.md. Exits 1 if the braces of a file do not balance.
 */

use function Phalcon\Tests\Benchmarks\Bin\loadScores;
use function Phalcon\Tests\Benchmarks\Bin\rankFindings;
use function Phalcon\Tests\Benchmarks\Bin\scanReport;
use function Phalcon\Tests\Benchmarks\Bin\writeFindings;

require __DIR__ . '/lib/scan.php';

const BUILTINS    = 'method_exists|class_exists|interface_exists|in_array|get_class|array_merge|array_key_exists'
    . '|is_callable';
const CLASS_LINE  = '/^\s*(?:(?:abstract|final)\s+)*(?:class|interface|trait)\s+(\w+)/';
const DYNAMIC     = '/\b(call_user_func_array|call_user_func|create_instance_params|create_instance)\s*\('
    . '|->\s*\{|::\s*\{|\bnew\s+\{/';
const HOT_RANK    = 50;
const METHOD_LINE = '/^\s*(?:(?:public|protected|private|static|final|abstract|inline|internal|deprecated)\s+)+'
    . 'function\s+(\w+)\s*\(/';
const PATTERNS = [
    'Z1-loop' => 'Property array write in a loop',
    'Z1'      => 'Property array write (not in a loop)',
    'Z2-loop' => 'Property array unset in a loop',
    'Z2'      => 'Property array unset (not in a loop)',
    'Z3'      => 'Property read in a loop',
    'Z4'      => '`isset` then read of the same key',
    'Z5'      => 'Method call on a variable in a loop',
    'Z6'      => 'Own method call in a loop',
    'Z7'      => 'Same method name called at two or more places',
    'Z8'      => 'Dynamic call',
    'Z9'      => 'Built-in function in a loop',
    'Z10'     => 'Untyped variables (count)',
];
// A write to a property or to a property array element (not ==, not =>)
const WRITE = '/this->(\w+)((?:\s*\[[^\]]*\])*)\s*(?:=|\+=|-=|\.=|\*=)(?![=>])/';

if (3 !== $argc) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/scan-zep.php <scores-tsv> <out-dir>' . PHP_EOL);
    exit(2);
}

[, $scoresFile, $out] = $argv;

if (!is_file($scoresFile)) {
    fwrite(STDERR, sprintf('Error: %s does not exist.', $scoresFile) . PHP_EOL);
    exit(1);
}

$root   = dirname(__DIR__, 3);
$scores = loadScores($scoresFile);

$files = [];
foreach (new RecursiveIteratorIterator(new RecursiveDirectoryIterator($root . '/phalcon')) as $item) {
    if ($item->isFile() && str_ends_with($item->getFilename(), '.zep')) {
        $files[] = $item->getPathname();
    }
}

sort($files);

/**
 * Splits a line into the text without comments, and the code without comments and without the text of string
 * literals (for the brace counter).
 */
$split = static function (string $line, bool &$inComment): array {
    $text   = '';
    $code   = '';
    $quote  = null;
    $length = strlen($line);
    for ($index = 0; $index < $length; $index++) {
        $char = $line[$index];
        $pair = substr($line, $index, 2);

        if ($inComment) {
            if ('*/' === $pair) {
                $inComment = false;
                $index++;
            }

            continue;
        }

        if (null !== $quote) {
            $text .= $char;
            if ('\\' === $char && $index + 1 < $length) {
                $text .= $line[++$index];
            } elseif ($char === $quote) {
                $code .= $char;
                $quote = null;
            }

            continue;
        }

        if ('//' === $pair) {
            break;
        }

        if ('/*' === $pair) {
            $inComment = true;
            $index++;
            continue;
        }

        if ('"' === $char || "'" === $char) {
            $quote = $char;
        }

        $text .= $char;
        $code .= $char;
    }

    return [$text, $code];
};

/**
 * Counts the names in a "var" declaration (commas inside brackets or parentheses do not count).
 */
$countNames = static function (string $declaration): int {
    $level = 0;
    $names = 1;
    foreach (str_split($declaration) as $char) {
        if ('[' === $char || '(' === $char) {
            $level++;
        } elseif (']' === $char || ')' === $char) {
            $level--;
        } elseif (',' === $char && 0 === $level) {
            $names++;
        }
    }

    return '' === trim($declaration) ? 0 : $names;
};

$findings = [];
$found    = [];
$errors   = [];

foreach ($files as $path) {
    $file      = substr($path, strlen($root) + 1);
    $namespace = '';
    $class     = '';
    $depth     = 0;
    $inComment = false;
    $method    = null;
    $pending   = null;
    $loopLine  = null;

    $add = static function (array $method, int $line, string $pattern, string $text) use (&$findings, $file): void {
        $findings[] = [
            'file'    => $file,
            'line'    => $line,
            'method'  => $method['key'],
            'pattern' => $pattern,
            'text'    => $text,
        ];
    };

    foreach (file($path, FILE_IGNORE_NEW_LINES) ?: [] as $index => $raw) {
        $number        = $index + 1;
        [$text, $code] = $split($raw, $inComment);
        $shown         = trim($text);

        if (null === $method && null === $pending) {
            if (1 === preg_match('/^\s*namespace\s+([\w\\\\]+)\s*;/', $text, $matches)) {
                $namespace = $matches[1];
            } elseif (1 === preg_match(CLASS_LINE, $text, $matches)) {
                $class = $namespace . '\\' . $matches[1];
            } elseif (1 === preg_match(METHOD_LINE, $text, $matches)) {
                $pending = $matches[1];
            }
        }

        $loops  = null === $method ? [] : $method['loops'];
        $inLoop = [] !== $loops;
        $loop   = $inLoop ? end($loops)['line'] : 0;

        if (null !== $method) {
            if (1 === preg_match('/^\s*(for|while|loop|do)\b/', $code)) {
                $loopLine = $number;
            }

            // Z1 and Z2: property array write and unset
            if (preg_match_all(WRITE, $text, $matches, PREG_SET_ORDER)) {
                foreach ($matches as $match) {
                    if ('' !== $match[2]) {
                        $add($method, $number, $inLoop ? 'Z1-loop' : 'Z1', $shown);
                    }
                }
            }

            if (1 === preg_match('/\bunset\s+this->\w+\s*\[/', $text)) {
                $add($method, $number, $inLoop ? 'Z2-loop' : 'Z2', $shown);
            }

            // Z3: property read in a loop (write targets and unset do not count)
            if ($inLoop) {
                $reads = (string) preg_replace([WRITE, '/\bunset\s+this->\w+/'], '', $text);
                if (preg_match_all('/this->(\w+)\b(?!\s*\()/', $reads, $matches)) {
                    foreach (array_unique($matches[1]) as $property) {
                        if (!isset($method['loopReads'][$loop][$property])) {
                            $method['loopReads'][$loop][$property] = true;
                            $add($method, $number, 'Z3', 'this->' . $property . ' (loop at line ' . $loop . ')');
                        }
                    }
                }
            }

            // Z4: isset then read of the same key
            $compact = (string) preg_replace('/\s+/', '', $text);
            foreach ($method['issets'] as $expression => $line) {
                $clean = str_replace(['isset' . $expression, 'unset' . $expression, $expression . '='], '', $compact);
                if (str_contains($clean, $expression)) {
                    $add($method, $number, 'Z4', '`isset ' . $expression . '` (line ' . $line . '), read: ' . $shown);
                    unset($method['issets'][$expression]);
                }
            }

            if (preg_match_all('/\bisset\s+((?:this->)?\w+(?:->\w+)*(?:\s*\[[^\]]+\])+)/', $text, $matches)) {
                foreach ($matches[1] as $expression) {
                    $method['issets'][(string) preg_replace('/\s+/', '', $expression)] = $number;
                }
            }

            if ($inLoop) {
                // Z5: method call on a variable
                if (preg_match_all('/\b([a-zA-Z_]\w*)->(\w+)\s*\(/', $text, $matches, PREG_SET_ORDER)) {
                    foreach ($matches as $match) {
                        if ('this' !== $match[1]) {
                            $add($method, $number, 'Z5', $match[1] . '->' . $match[2] . '() in: ' . $shown);
                        }
                    }
                }

                // Z6: own method call
                if (preg_match_all('/(?:\bthis->|\bself::|\bstatic::|\bparent::)(\w+)\s*\(/', $text, $matches)) {
                    foreach ($matches[1] as $name) {
                        $add($method, $number, 'Z6', $name . '() in: ' . $shown);
                    }
                }

                // Z9: built-in function
                if (preg_match_all('/\b(' . BUILTINS . ')\s*\(/', $text, $matches)) {
                    foreach ($matches[1] as $name) {
                        $add($method, $number, 'Z9', $name . '() in: ' . $shown);
                    }
                }
            }

            // Z7: calls by method name
            if (preg_match_all('/(?:->|::)(\w+)\s*\(/', $text, $matches)) {
                foreach ($matches[1] as $name) {
                    $method['calls'][strtolower($name)][] = $number;
                }
            }

            // Z8: dynamic call
            if (1 === preg_match(DYNAMIC, $text)) {
                $add($method, $number, 'Z8', $shown);
            }

            // Z10: untyped variables ("var a, b;", can span lines)
            if (null !== $method['declaration']) {
                $method['declaration'] .= ' ' . $text;
            } elseif (1 === preg_match('/^\s*var\s+(.*)$/', $text, $matches)) {
                $method['declaration'] = $matches[1];
            }

            if (null !== $method['declaration'] && str_contains($method['declaration'], ';')) {
                $method['vars']       += $countNames(strstr($method['declaration'], ';', true));
                $method['declaration'] = null;
            }
        }

        foreach (str_split($code) as $char) {
            if ('{' === $char) {
                $depth++;
                if (null !== $pending && null === $method) {
                    $key    = $class . '::' . $pending;
                    $method = [
                        'calls'       => [],
                        'declaration' => null,
                        'depth'       => $depth,
                        'issets'      => [],
                        'key'         => $key,
                        'line'        => $number,
                        'loopReads'   => [],
                        'loops'       => [],
                        'vars'        => 0,
                    ];

                    $found[strtolower($key)] = true;
                    $pending                 = null;
                } elseif (null !== $method && null !== $loopLine) {
                    $method['loops'][] = ['depth' => $depth, 'line' => $loopLine];
                    $loopLine          = null;
                }
            } elseif ('}' === $char) {
                if (null !== $method) {
                    if ([] !== $method['loops'] && end($method['loops'])['depth'] === $depth) {
                        array_pop($method['loops']);
                    }

                    if ($method['depth'] === $depth) {
                        foreach ($method['calls'] as $name => $lines) {
                            if (count($lines) >= 2) {
                                $add(
                                    $method,
                                    $lines[0],
                                    'Z7',
                                    $name . '() x' . count($lines) . ' (lines ' . implode(', ', $lines) . ')'
                                );
                            }
                        }

                        if ($method['vars'] > 0) {
                            $add($method, $method['line'], 'Z10', $method['vars'] . ' untyped variables');
                        }

                        $method = null;
                    }
                }

                $depth--;
            } elseif (';' === $char && null !== $pending && null === $method) {
                // A method with no body (abstract or interface)
                $pending = null;
            }
        }
    }

    if (0 !== $depth) {
        $errors[] = $file . ' (depth ' . $depth . ' at the end)';
    }
}

if (!is_dir($out)) {
    mkdir($out, 0777, true);
}

$ranked = rankFindings($findings, $scores);
writeFindings($ranked, $out . '/zep-findings.tsv');
file_put_contents(
    $out . '/zep-report.md',
    scanReport('Static scan: Zephir source', $ranked, $scores, $found, PATTERNS, HOT_RANK)
);

echo 'Files: ', count($files), '; methods: ', count($found), '; findings: ', count($ranked), PHP_EOL;
echo 'Report: ', $out, '/zep-report.md', PHP_EOL;

if ([] !== $errors) {
    fwrite(STDERR, 'Error: the braces do not balance in:' . PHP_EOL . implode(PHP_EOL, $errors) . PHP_EOL);
    exit(1);
}
