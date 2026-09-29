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
 * Compares two results folders of bin/run-all and bin/run-time (A = before, B = after). Each difference is
 * "better", "worse" or "noise". A lower value is better for all metrics. A difference counts only if it is
 * at or above both thresholds of its metric (relative and absolute), else it is noise.
 *
 * Usage: php tests/benchmarks/bin/compare.php <folder-a> <folder-b>
 */

if (3 !== $argc) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/compare.php <folder-a> <folder-b>' . PHP_EOL);
    exit(2);
}

/**
 * metric => [relative threshold, absolute threshold]
 *
 * The absolute thresholds are 3 times the largest difference of an A/A run (the same build two times,
 * 2026-09-29: warm_ir 21.8 Ir, cold_ir 2,505 Ir, cold allocations 2, warm bytes 1). The relative floors
 * cover layout effects: a change in unrelated code moved a small subject by 0.35%.
 */
$thresholds = [
    'warm_ir'                 => [0.005, 70],
    'cold_ir'                 => [0.01, 7500],
    'warm_allocations'        => [0.0, 1],
    'cold_allocations'        => [0.0, 6],
    'warm_bytes'              => [0.01, 3],
    'peak_bytes'              => [0.01, 64],
    'retained_bytes_per_call' => [0.01, 64],
    'leaked_bytes_per_call'   => [0.01, 64],
    'cycles_per_call'         => [0.0, 1],
    // Wall time (pinned to one CPU): the largest A/A difference was 3.99%
    'mode_us'                 => [0.05, 0],
];

/**
 * Reads a TSV file with a header line. Returns [subject => [column => value]].
 */
$read = static function (string $file): array {
    if (!is_file($file)) {
        return [];
    }

    $lines  = file($file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    $header = explode("\t", (string) array_shift($lines));
    $rows   = [];
    foreach ($lines as $line) {
        $values = explode("\t", $line);
        if (count($values) === count($header)) {
            $row                   = array_combine($header, $values);
            $rows[$row['subject']] = $row;
        }
    }

    return $rows;
};

/**
 * Reads metrics.tsv and time.tsv of a folder. The time rows use the short class name: they are joined to
 * the metric rows by "<short class>::<method>".
 */
$load = static function (string $folder) use ($read): array {
    if (!is_dir($folder)) {
        fwrite(STDERR, sprintf('Error: %s is not a folder.', $folder) . PHP_EOL);
        exit(2);
    }

    $data = $read($folder . '/metrics.tsv');
    foreach ($read($folder . '/time.tsv') as $short => $row) {
        $subject = $short;
        foreach (array_keys($data) as $name) {
            if (str_ends_with($name, '\\' . $short)) {
                $subject = $name;
                break;
            }
        }
        $data[$subject]['mode_us'] = $row['mode_us'];
    }

    return $data;
};

[, $folderA, $folderB] = $argv;

$dataA = $load($folderA);
$dataB = $load($folderB);

$results  = [];
$counts   = ['better' => 0, 'noise' => 0, 'worse' => 0];
$subjects = array_unique(array_merge(array_keys($dataA), array_keys($dataB)));
sort($subjects);

foreach ($subjects as $subject) {
    foreach ($thresholds as $metric => [$relative, $absolute]) {
        if (!isset($dataA[$subject][$metric], $dataB[$subject][$metric])) {
            continue;
        }

        $valueA = (float) $dataA[$subject][$metric];
        $valueB = (float) $dataB[$subject][$metric];
        $change = $valueB - $valueA;
        $ratio  = 0.0 == $valueA ? (0.0 == $change ? 0.0 : INF) : $change / abs($valueA);

        $result = 'noise';
        if (0.0 != $change && abs($change) >= $absolute && abs($ratio) >= $relative) {
            $result = $change < 0 ? 'better' : 'worse';
        }

        $counts[$result]++;
        $results[] = [$subject, $metric, $valueA, $valueB, $change, $ratio, $result];
    }
}

$number = static function (float $value): string {
    return floor($value) == $value ? number_format($value, 0, '.', ',') : number_format($value, 1, '.', ',');
};

$percent = static function (float $ratio): string {
    return is_infinite($ratio) ? 'new' : sprintf('%+.2f%%', 100 * $ratio);
};

$short = static function (string $subject): string {
    return str_replace('Phalcon\\Tests\\Benchmarks\\', '', $subject);
};

$lines   = [];
$lines[] = '# Compare';
$lines[] = '';
$lines[] = '- A: `' . $folderA . '`';
$lines[] = '- B: `' . $folderB . '`';
$lines[] = sprintf(
    '- Result: %d better, %d worse, %d noise',
    $counts['better'],
    $counts['worse'],
    $counts['noise']
);

foreach (array_keys($dataA + $dataB) as $subject) {
    if (!isset($dataA[$subject])) {
        $lines[] = '- Only in B: `' . $short((string) $subject) . '`';
    } elseif (!isset($dataB[$subject])) {
        $lines[] = '- Only in A: `' . $short((string) $subject) . '`';
    }
}

$lines[] = '';
$lines[] = '## Changes above the thresholds';
$lines[] = '';
$lines[] = '| Subject | Metric | A | B | Change | Change % | Result |';
$lines[] = '|---|---|---:|---:|---:|---:|---|';
foreach ($results as [$subject, $metric, $valueA, $valueB, $change, $ratio, $result]) {
    if ('noise' !== $result) {
        $lines[] = sprintf(
            '| `%s` | %s | %s | %s | %s | %s | **%s** |',
            $short($subject),
            $metric,
            $number($valueA),
            $number($valueB),
            $number($change),
            $percent($ratio),
            $result
        );
    }
}

$lines[] = '';
$lines[] = '## Main number (warm_ir)';
$lines[] = '';
$lines[] = '| Subject | A | B | Change % | Result |';
$lines[] = '|---|---:|---:|---:|---|';
foreach ($results as [$subject, $metric, $valueA, $valueB, , $ratio, $result]) {
    if ('warm_ir' === $metric) {
        $lines[] = sprintf(
            '| `%s` | %s | %s | %s | %s |',
            $short($subject),
            $number($valueA),
            $number($valueB),
            $percent($ratio),
            $result
        );
    }
}

echo implode(PHP_EOL, $lines), PHP_EOL;
