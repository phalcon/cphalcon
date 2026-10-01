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

namespace Phalcon\Tests\Benchmarks\Bin;

/**
 * Shared code of the static scanners (bin/scan-zep.php, bin/scan-c.php).
 *
 * A finding is an array with the keys: method ("Class::method"), file, line, pattern, text.
 */

/**
 * Reads _scores.tsv of bin/rank.php. Returns lowercase "class::method" => [method, score, rank].
 */
function loadScores(string $file): array
{
    $scores = [];
    foreach (array_slice(file($file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES) ?: [], 1) as $line) {
        [$method, $score, , $rank] = explode("\t", $line);

        $scores[strtolower($method)] = [
            'method' => $method,
            'rank'   => (int) $rank,
            'score'  => (float) $score,
        ];
    }

    return $scores;
}

/**
 * Adds the score and the rank to each finding and sorts them: ranked methods first (rank order), then by file
 * and line.
 */
function rankFindings(array $findings, array $scores): array
{
    foreach ($findings as $index => $finding) {
        $score = $scores[strtolower($finding['method'])] ?? null;

        $findings[$index]['rank']  = null === $score ? PHP_INT_MAX : $score['rank'];
        $findings[$index]['score'] = null === $score ? '' : (string) $score['score'];
    }

    usort(
        $findings,
        static function (array $left, array $right): int {
            return [$left['rank'], $left['file'], $left['line']] <=> [$right['rank'], $right['file'], $right['line']];
        }
    );

    return $findings;
}

/**
 * Writes the findings (ranked) as TSV: score, rank, method, file, line, pattern, text.
 */
function writeFindings(array $findings, string $file): void
{
    $lines = ["score\trank\tmethod\tfile\tline\tpattern\ttext"];
    foreach ($findings as $finding) {
        $lines[] = implode(
            "\t",
            [
                $finding['score'],
                PHP_INT_MAX === $finding['rank'] ? '' : $finding['rank'],
                $finding['method'],
                $finding['file'],
                $finding['line'],
                $finding['pattern'],
                str_replace("\t", ' ', $finding['text']),
            ]
        );
    }

    file_put_contents($file, implode(PHP_EOL, $lines) . PHP_EOL);
}

/**
 * Returns the report (markdown): findings of the hot methods, pattern counts, files with the most findings
 * outside the hot methods, and the hot methods with no method block in the scanned files.
 *
 * $methods: lowercase "class::method" of all method blocks found. $patterns: pattern ID => description.
 */
function scanReport(
    string $title,
    array $findings,
    array $scores,
    array $methods,
    array $patterns,
    int $hotRank
): string {
    $lines = ['# ' . $title, ''];

    $hot = [];
    foreach ($scores as $key => $score) {
        if ($score['rank'] <= $hotRank) {
            $hot[$key] = $score;
        }
    }

    uasort(
        $hot,
        static function (array $left, array $right): int {
            return $left['rank'] <=> $right['rank'];
        }
    );

    $byMethod = [];
    foreach ($findings as $finding) {
        $byMethod[strtolower($finding['method'])][] = $finding;
    }

    $lines[] = '## Hot methods (rank 1 to ' . $hotRank . ')';
    foreach ($hot as $key => $score) {
        $lines[] = '';
        $lines[] = '### ' . $score['rank'] . '. `' . $score['method'] . '` (score ' . $score['score'] . '%)';
        $lines[] = '';
        if (!isset($methods[$key])) {
            $lines[] = '- No method block in the scanned files.';
            continue;
        }

        if (!isset($byMethod[$key])) {
            $lines[] = '- No finding.';
            continue;
        }

        foreach ($byMethod[$key] as $finding) {
            $lines[] = '- ' . $finding['pattern'] . ' `' . $finding['file'] . ':' . $finding['line'] . '` '
                . str_replace('|', '\|', $finding['text']);
        }
    }

    $lines[] = '';
    $lines[] = '## Pattern counts';
    $lines[] = '';
    $lines[] = '| Pattern | Description | Hot methods | All methods |';
    $lines[] = '|---|---|---:|---:|';
    foreach ($patterns as $pattern => $description) {
        $all    = 0;
        $inHot  = 0;
        foreach ($findings as $finding) {
            if ($finding['pattern'] !== $pattern) {
                continue;
            }

            $all++;
            if ($finding['rank'] <= $hotRank) {
                $inHot++;
            }
        }

        $lines[] = '| ' . $pattern . ' | ' . $description . ' | ' . $inHot . ' | ' . $all . ' |';
    }

    $files = [];
    foreach ($findings as $finding) {
        if ($finding['rank'] > $hotRank) {
            $files[$finding['file']] = ($files[$finding['file']] ?? 0) + 1;
        }
    }

    arsort($files);

    $lines[] = '';
    $lines[] = '## Files with the most findings outside the hot methods';
    $lines[] = '';
    $lines[] = '| File | Findings |';
    $lines[] = '|---|---:|';
    foreach (array_slice($files, 0, 20, true) as $file => $count) {
        $lines[] = '| `' . $file . '` | ' . $count . ' |';
    }

    $missing = [];
    foreach ($hot as $key => $score) {
        if (!isset($methods[$key])) {
            $missing[] = '- ' . $score['rank'] . '. `' . $score['method'] . '`';
        }
    }

    $lines[] = '';
    $lines[] = '## Hot methods with no method block';
    $lines[] = '';
    array_push($lines, ...([] === $missing ? ['- none'] : $missing));

    return implode(PHP_EOL, $lines) . PHP_EOL;
}
