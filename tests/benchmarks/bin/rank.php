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
 * Reads the TSV files of bin/attribute in a folder and writes one ranking for all subjects to
 * <folder>/_ranking.md:
 * 1. totals for each app (the subjects in Benchmarks\Apps\);
 * 2. Phalcon methods by score (the sum of the shares of the app requests; each app request counts the same);
 * 3. the parts of the own Ir of the top 20 methods;
 * 4. helpers by score;
 * 5. the micro subjects in which a top method has 5% or more of the subject total.
 *
 * Usage: php tests/benchmarks/bin/rank.php <folder>
 */

const APP_PREFIX = 'Phalcon.Tests.Benchmarks.Apps.';
const MAP_SHARE  = 5.0;

if (2 !== $argc) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/rank.php <folder>' . PHP_EOL);
    exit(2);
}

$folder = rtrim($argv[1], '/');
$files  = glob($folder . '/*.tsv') ?: [];
if ([] === $files) {
    fwrite(STDERR, sprintf('Error: no TSV file in %s.', $folder) . PHP_EOL);
    exit(1);
}

/**
 * Subjects: name => [app, label, total, rows]. A row is [owner, helper, calls, self].
 */
$subjects = [];
foreach ($files as $file) {
    $name  = basename($file, '.tsv');
    $lines = file($file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES) ?: [];
    $total = 0.0;
    $rows  = [];
    foreach (array_slice($lines, 1) as $line) {
        [$owner, $helper, $calls, $self] = explode("\t", $line);
        if ('_total' === $owner) {
            $total = (float) $self;
            continue;
        }

        $rows[] = [$owner, $helper, (float) $calls, (float) $self];
    }

    if (0.0 === $total) {
        fwrite(STDERR, sprintf('Error: no total in %s.', $file) . PHP_EOL);
        exit(1);
    }

    // "Phalcon.Tests.Benchmarks.Apps.Mvc.MvcBench-benchPage" => "Mvc page"
    [$class, $method] = explode('-', $name, 2);
    $shortClass       = substr($class, (int) strrpos($class, '.') + 1);
    $label            = preg_replace('/Bench$/', '', $shortClass) . ' '
        . lcfirst((string) preg_replace('/^bench/', '', $method));

    $subjects[$name] = [
        'app'   => str_starts_with($name, APP_PREFIX),
        'label' => $label,
        'rows'  => $rows,
        'total' => $total,
    ];
}

ksort($subjects);

$apps = array_filter(
    $subjects,
    static function (array $subject): bool {
        return $subject['app'];
    }
);

$number = static function (float $value, int $decimals = 0): string {
    return number_format($value, $decimals, '.', ',');
};

$percent = static function (float $value): string {
    return number_format($value, 2) . '%';
};

$isMethod = static function (string $owner): bool {
    return !str_starts_with($owner, '(');
};

/**
 * Own Ir for each owner in each app, and the parts (helpers) of each method.
 */
$methods = [];
$helpers = [];
$totals  = [];
foreach ($apps as $name => $subject) {
    $totals[$name] = ['methods' => 0.0, 'owners' => 0.0];
    foreach ($subject['rows'] as [$owner, $helper, $calls, $self]) {
        $share                   = 100 * $self / $subject['total'];
        $totals[$name]['owners'] += $self;
        if (!$isMethod($owner)) {
            $totals[$name][$owner] = ($totals[$name][$owner] ?? 0.0) + $self;
            continue;
        }

        $totals[$name]['methods'] += $self;

        $methods[$owner]               = $methods[$owner] ?? ['own' => [], 'parts' => [], 'score' => 0.0];
        $methods[$owner]['own'][$name] = ($methods[$owner]['own'][$name] ?? 0.0) + $self;
        $methods[$owner]['score']     += $share;

        $part = $methods[$owner]['parts'][$helper] ?? ['calls' => 0.0, 'self' => 0.0];

        $part['calls']                    += $calls;
        $part['self']                     += $self;
        $methods[$owner]['parts'][$helper] = $part;

        if ('(self)' !== $helper) {
            $helpers[$helper] = $helpers[$helper] ?? ['calls' => 0.0, 'owners' => [], 'score' => 0.0, 'self' => 0.0];
            $helpers[$helper]['calls']          += $calls;
            $helpers[$helper]['self']           += $self;
            $helpers[$helper]['score']          += $share;
            $helpers[$helper]['owners'][$owner] = ($helpers[$helper]['owners'][$owner] ?? 0.0) + $share;
        }
    }
}

$byScore = static function (array $left, array $right): int {
    return $right['score'] <=> $left['score'];
};

uasort($methods, $byScore);
uasort($helpers, $byScore);

$topMethods = array_slice($methods, 0, 50, true);

$lines   = [];
$lines[] = '# Own cost ranking';
$lines[] = '';
$lines[] = '- Source: the TSV files of `bin/attribute` in `' . $folder . '` (warm, one call).';
$lines[] = '- Share: own Ir / warm total of the app request. Score: the sum of the shares of the '
    . count($apps) . ' app requests (each app request counts the same).';

$lines[] = '';
$lines[] = '## 1. Totals for each app';
$lines[] = '';
$lines[] = '| App | Warm total Ir | Phalcon methods | (userland) | (shutdown) | (gc) | (unattributed) | Owners sum |';
$lines[] = '|---|---:|---:|---:|---:|---:|---:|---:|';
foreach ($apps as $name => $subject) {
    $cells = [$number($subject['total'])];
    foreach (['methods', '(userland)', '(shutdown)', '(gc)', '(unattributed)', 'owners'] as $key) {
        $cells[] = $percent(100 * ($totals[$name][$key] ?? 0.0) / $subject['total']);
    }

    $lines[] = '| ' . $subject['label'] . ' | ' . implode(' | ', $cells) . ' |';
}

$lines[] = '';
$lines[] = '## 2. Phalcon methods (top 50 by score)';
$lines[] = '';
$header  = '| # | Method | Apps | Score |';
$divider = '|---:|---|---:|---:|';
foreach ($apps as $subject) {
    $header  .= ' ' . $subject['label'] . ' |';
    $divider .= '---:|';
}
$lines[] = $header;
$lines[] = $divider;
$rank    = 0;
foreach ($topMethods as $method => $values) {
    $cells = [];
    $count = 0;
    foreach ($apps as $name => $subject) {
        $own = $values['own'][$name] ?? 0.0;
        if ($own >= 0.5) {
            $count++;
        }

        $cells[] = $own >= 0.5 ? $number($own) . ' (' . $percent(100 * $own / $subject['total']) . ')' : '-';
    }

    $lines[] = '| ' . ++$rank . ' | `' . $method . '` | ' . $count . ' | ' . $percent($values['score']) . ' | '
        . implode(' | ', $cells) . ' |';
}

$lines[] = '';
$lines[] = '## 3. Parts of the own Ir (top 20 methods, all apps together)';
$lines[] = '';
$lines[] = '| Method | Own Ir | Parts (share of own Ir, calls) |';
$lines[] = '|---|---:|---|';
foreach (array_slice($topMethods, 0, 20, true) as $method => $values) {
    $own   = array_sum($values['own']);
    $parts = $values['parts'];
    uasort(
        $parts,
        static function (array $left, array $right): int {
            return $right['self'] <=> $left['self'];
        }
    );

    $texts = [];
    foreach (array_slice($parts, 0, 6, true) as $helper => $part) {
        $texts[] = '`' . $helper . '` ' . $percent(100 * $part['self'] / $own) . ', ' . $number($part['calls'], 1);
    }

    $lines[] = '| `' . $method . '` | ' . $number($own) . ' | ' . implode('; ', $texts) . ' |';
}

$lines[] = '';
$lines[] = '## 4. Helpers (top 30 by score)';
$lines[] = '';
$lines[] = '| Helper | Score | Ir (apps sum) | Calls (apps sum) | Top owners (score) |';
$lines[] = '|---|---:|---:|---:|---|';
foreach (array_slice($helpers, 0, 30, true) as $helper => $values) {
    arsort($values['owners']);

    $texts = [];
    foreach (array_slice($values['owners'], 0, 3, true) as $owner => $score) {
        $texts[] = '`' . $owner . '` ' . $percent($score);
    }

    $lines[] = '| `' . $helper . '` | ' . $percent($values['score']) . ' | ' . $number($values['self'])
        . ' | ' . $number($values['calls'], 1) . ' | ' . implode('; ', $texts) . ' |';
}

$lines[] = '';
$lines[] = '## 5. Micro subjects for the top 50 methods (own Ir ' . MAP_SHARE . '% or more of the subject)';
$lines[] = '';
$lines[] = '| Method | Micro subjects (own Ir, share) |';
$lines[] = '|---|---|';
foreach (array_keys($topMethods) as $method) {
    $texts = [];
    foreach ($subjects as $subject) {
        if ($subject['app']) {
            continue;
        }

        $own = 0.0;
        foreach ($subject['rows'] as [$owner, , , $self]) {
            if ($owner === $method) {
                $own += $self;
            }
        }

        $share = 100 * $own / $subject['total'];
        if ($share >= MAP_SHARE) {
            $texts[] = $subject['label'] . ' ' . $number($own) . ' (' . $percent($share) . ')';
        }
    }

    $lines[] = '| `' . $method . '` | ' . ([] === $texts ? '-' : implode('; ', $texts)) . ' |';
}

$ranking = $folder . '/_ranking.md';
file_put_contents($ranking, implode(PHP_EOL, $lines) . PHP_EOL);

echo 'Ranking: ', $ranking, PHP_EOL;
