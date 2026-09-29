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
 * Measures the memory of one benchmark subject (in bytes of the PHP memory manager):
 * - peak: the peak of one call, above the memory before the call;
 * - retained: the memory that stays after k calls, for each call, before a garbage collection;
 * - leaked: the same after a garbage collection (memory that is still referenced);
 * - cycles: the reference cycles that the garbage collector collected, for each call.
 *
 * Usage: php tests/benchmarks/bin/memory.php <class> <method> <k>
 */

use function Phalcon\Tests\Benchmarks\Bin\prepareSubject;

require dirname(__DIR__, 3) . '/vendor/autoload.php';
require __DIR__ . '/lib/subject.php';

if (4 !== $argc || !ctype_digit($argv[3]) || 1 > (int) $argv[3]) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/memory.php <class> <method> <k>' . PHP_EOL);
    exit(2);
}

[, $class, $method, $k] = $argv;

$k = (int) $k;

if (!method_exists($class, $method)) {
    fwrite(STDERR, sprintf('Error: %s::%s() does not exist.', $class, $method) . PHP_EOL);
    exit(1);
}

$subject = prepareSubject($class, $method);

/**
 * Warm-up call: lazy setup and file caches.
 */
$subject->$method();
gc_collect_cycles();

/**
 * The peak of one call.
 */
$before = memory_get_usage();
memory_reset_peak_usage();
$subject->$method();
$peak = memory_get_peak_usage() - $before;

/**
 * The memory that stays after k calls.
 */
gc_collect_cycles();
$start           = memory_get_usage();
$collectedBefore = gc_status()['collected'];
for ($index = 0; $index < $k; $index++) {
    $subject->$method();
}
$retained  = memory_get_usage() - $start;
$collected = gc_collect_cycles();
$leaked    = memory_get_usage() - $start;
$cycles    = gc_status()['collected'] - $collectedBefore;

echo 'k=', $k, PHP_EOL;
echo 'peak_bytes=', $peak, PHP_EOL;
echo 'retained_bytes_per_call=', round($retained / $k, 1), PHP_EOL;
echo 'leaked_bytes_per_call=', round($leaked / $k, 1), PHP_EOL;
echo 'cycles_per_call=', round($cycles / $k, 1), PHP_EOL;
echo 'cycles_collected_at_end=', $collected, PHP_EOL;
