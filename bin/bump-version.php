#!/usr/bin/env php
<?php

declare(strict_types=1);

/**
 * Bumps the project version across every file that hard-codes it.
 *
 * Usage:
 *   php bin/bump-version.php <version> [--date=YYYY-MM-DD]
 *
 * Examples:
 *   php bin/bump-version.php 5.14.0
 *   php bin/bump-version.php 5.14.0-RC1
 *   php bin/bump-version.php 5.14.0-alpha2
 *   php bin/bump-version.php 5.14.0-beta1 --date=2026-06-15
 */

$scriptName = $argv[0] ?? 'bin/bump-version.php';
array_shift($argv);

$version = null;
$date    = date('Y-m-d');

foreach ($argv as $arg) {
    if (str_starts_with($arg, '--date=')) {
        $date = substr($arg, 7);
        continue;
    }

    if ($version === null) {
        $version = $arg;
        continue;
    }

    fwrite(STDERR, "Unknown argument: {$arg}\n");
    exit(1);
}

if ($version === null) {
    fwrite(STDERR, "Usage: {$scriptName} <version> [--date=YYYY-MM-DD]\n");
    exit(1);
}

if (!preg_match('/^(\d+)\.(\d+)\.(\d+)(?:-(alpha|beta|RC)(\d+))?$/', $version, $matches)) {
    fwrite(STDERR, "Invalid version '{$version}'. Expected MAJOR.MEDIUM.MINOR[-(alpha|beta|RC)N].\n");
    exit(1);
}

if (!preg_match('/^\d{4}-\d{2}-\d{2}$/', $date)) {
    fwrite(STDERR, "Invalid date '{$date}'. Expected YYYY-MM-DD.\n");
    exit(1);
}

$major         = (int) $matches[1];
$medium        = (int) $matches[2];
$minor         = (int) $matches[3];
$suffixWord    = $matches[4] ?? '';
$specialNumber = (int) ($matches[5] ?? 0);

$specialMap   = ['alpha' => 1, 'beta' => 2, 'RC' => 3];
$special      = $suffixWord === '' ? 4 : $specialMap[$suffixWord];

$stabilityMap = [1 => 'alpha', 2 => 'beta', 3 => 'beta', 4 => 'stable'];
$stability    = $stabilityMap[$special];

$displayVersion = $major . '.' . $medium . '.' . $minor;
if ($suffixWord !== '') {
    $displayVersion .= $suffixWord;
    if ($specialNumber > 0) {
        $displayVersion .= $specialNumber;
    }
}

$root = dirname(__DIR__);

$configPath  = $root . '/config.json';
$oldVersion  = null;
if (is_file($configPath)) {
    $config = json_decode((string) file_get_contents($configPath), true);
    if (is_array($config) && isset($config['version']) && is_string($config['version'])) {
        $oldVersion = $config['version'];
    }
}

$tasks = [
    [
        'file'    => $root . '/package.xml',
        'patches' => [
            [
                '/<date>\d{4}-\d{2}-\d{2}<\/date>/',
                '<date>' . $date . '</date>',
            ],
            [
                '/<version>\s*<release>[^<]*<\/release>\s*<api>[^<]*<\/api>\s*<\/version>/',
                "<version>\n    <release>{$displayVersion}</release>\n    <api>{$displayVersion}</api>\n  </version>",
            ],
            [
                '/<stability>\s*<release>[^<]*<\/release>\s*<api>[^<]*<\/api>\s*<\/stability>/',
                "<stability>\n    <release>{$stability}</release>\n    <api>{$stability}</api>\n  </stability>",
            ],
        ],
    ],
    [
        'file'    => $configPath,
        'patches' => [
            [
                '/"version":\s*"[^"]*"/',
                '"version": "' . $displayVersion . '"',
            ],
        ],
    ],
    [
        'file'    => $root . '/.github/workflows/main.yml',
        'patches' => [
            [
                '/^(\s*PHALCON_VERSION:\s*).*$/m',
                '${1}' . $displayVersion,
            ],
        ],
    ],
    [
        'file'    => $root . '/docker/Dockerfile',
        'patches' => [
            [
                '/ARG PHALCON_VERSION="v[^"]*"/',
                'ARG PHALCON_VERSION="v' . $displayVersion . '"',
            ],
        ],
    ],
    [
        'file'    => $root . '/phalcon/Support/Version.zep',
        'patches' => [
            [
                '/return\s*\[\s*\d+\s*,\s*\d+\s*,\s*\d+\s*,\s*\d+\s*,\s*\d+\s*\]\s*;/',
                "return [{$major}, {$medium}, {$minor}, {$special}, {$specialNumber}];",
            ],
        ],
    ],
];

$errors        = [];
$touchedFiles  = [];

foreach ($tasks as $task) {
    $file = $task['file'];

    if (!is_file($file)) {
        $errors[] = "missing file: {$file}";
        continue;
    }

    $original = (string) file_get_contents($file);
    $updated  = $original;

    foreach ($task['patches'] as [$pattern, $replacement]) {
        $count = 0;
        $next  = preg_replace($pattern, $replacement, $updated, -1, $count);

        if ($next === null) {
            $errors[] = "{$file}: regex error for {$pattern}";
            continue 2;
        }

        if ($count === 0) {
            $errors[] = "{$file}: pattern not matched: {$pattern}";
            continue 2;
        }

        $updated = $next;
    }

    if ($updated === $original) {
        echo "  unchanged: " . substr($file, strlen($root) + 1) . "\n";
        continue;
    }

    file_put_contents($file, $updated);
    $touchedFiles[] = $file;
    echo "  updated:   " . substr($file, strlen($root) + 1) . "\n";
}

if ($errors !== []) {
    fwrite(STDERR, "\nErrors:\n");
    foreach ($errors as $error) {
        fwrite(STDERR, "  - {$error}\n");
    }
    exit(1);
}

if ($oldVersion !== null && $oldVersion !== $displayVersion) {
    $stragglers = [];
    foreach ($touchedFiles as $file) {
        $contents = (string) file_get_contents($file);
        if (strpos($contents, $oldVersion) !== false) {
            $stragglers[] = substr($file, strlen($root) + 1);
        }
    }

    if ($stragglers !== []) {
        echo "\nWarning: old version '{$oldVersion}' still appears in:\n";
        foreach ($stragglers as $straggler) {
            echo "  - {$straggler}\n";
        }
    }
}

echo "\nVersion: {$displayVersion} (stability: {$stability}, date: {$date})\n";
echo "Array:   [{$major}, {$medium}, {$minor}, {$special}, {$specialNumber}]\n";

/**
 * Recompile the extension. Mirrors the docker `cpl` alias so the steps live in
 * source control. Intended to be run inside the cphalcon-dev-* container.
 */
$runStep = function (string $label, string $cwd, array $command) {
    echo "\n>>> {$label}\n";

    if (!chdir($cwd)) {
        fwrite(STDERR, "  failed to chdir to {$cwd}\n");
        exit(1);
    }

    $line = implode(' ', array_map('escapeshellarg', $command));
    passthru($line, $exitCode);

    if ($exitCode !== 0) {
        fwrite(STDERR, "  step '{$label}' failed (exit {$exitCode})\n");
        exit($exitCode);
    }
};

$runStep('zephir fullclean', $root,            ['zephir', 'fullclean']);
$runStep('zephir generate',  $root,            ['zephir', 'generate']);
$runStep('ext/install',      $root . '/ext',   ['./install']);
$runStep('build/gen-build',  $root . '/build', ['php', 'gen-build.php']);

echo "\nDone.\n";