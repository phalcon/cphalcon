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
 * Prints all benchmark subjects, one line for each subject: "<class> TAB <method> TAB <revs>".
 * The revs come from #[Revs] of the method, else from #[Revs] of the class, else from "runner.revs" of
 * resources/phpbench.json.
 *
 * Usage: php tests/benchmarks/bin/subjects.php [filter]
 *
 * [filter] is a regular expression without delimiters (and without "~") on "<class>::<method>".
 */

use PhpBench\Attributes\Revs;

require dirname(__DIR__, 3) . '/vendor/autoload.php';

if ($argc > 2) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/subjects.php [filter]' . PHP_EOL);
    exit(2);
}

$filter = $argv[1] ?? '';
if ('' !== $filter && false === @preg_match('~' . $filter . '~', '')) {
    fwrite(STDERR, 'Error: the filter is not a valid regular expression.' . PHP_EOL);
    exit(2);
}

$root    = dirname(__DIR__);
$config  = json_decode((string) file_get_contents(dirname(__DIR__, 3) . '/resources/phpbench.json'), true);
$default = (int) ($config['runner.revs'] ?? 1);

$files = new RecursiveIteratorIterator(
    new RecursiveDirectoryIterator($root, FilesystemIterator::SKIP_DOTS)
);

$lines = [];
foreach ($files as $file) {
    if (!str_ends_with($file->getFilename(), 'Bench.php')) {
        continue;
    }

    $relative   = substr($file->getPathname(), strlen($root) + 1, -4);
    $class      = 'Phalcon\\Tests\\Benchmarks\\' . str_replace('/', '\\', $relative);
    $reflection = new ReflectionClass($class);
    $classRevs  = $reflection->getAttributes(Revs::class);

    foreach ($reflection->getMethods(ReflectionMethod::IS_PUBLIC) as $method) {
        if ($method->class !== $class || !str_starts_with($method->name, 'bench')) {
            continue;
        }

        if ('' !== $filter && 1 !== preg_match('~' . $filter . '~', $class . '::' . $method->name)) {
            continue;
        }

        $attributes = $method->getAttributes(Revs::class) ?: $classRevs;
        $revs       = [] === $attributes ? $default : $attributes[0]->newInstance()->revs[0];
        $lines[]    = $class . "\t" . $method->name . "\t" . $revs;
    }
}

sort($lines);
echo implode(PHP_EOL, $lines), PHP_EOL;
