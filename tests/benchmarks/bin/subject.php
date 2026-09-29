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
 * Runs one benchmark subject <count> times, for the instruction counter (instr).
 *
 * Usage: php tests/benchmarks/bin/subject.php <class> <method> <count>
 *
 * The script calls the #[BeforeMethods] methods of the class and of the subject one time. Then it calls the
 * subject <count> times. <count> can be 0. A subject throws an exception if its result is wrong.
 */

use function Phalcon\Tests\Benchmarks\Bin\prepareSubject;

require dirname(__DIR__, 3) . '/vendor/autoload.php';
require __DIR__ . '/lib/subject.php';

if (4 !== $argc || !ctype_digit($argv[3])) {
    fwrite(STDERR, 'Usage: php tests/benchmarks/bin/subject.php <class> <method> <count>' . PHP_EOL);
    exit(2);
}

[, $class, $method, $count] = $argv;

if (!method_exists($class, $method)) {
    fwrite(STDERR, sprintf('Error: %s::%s() does not exist.', $class, $method) . PHP_EOL);
    exit(1);
}

$subject = prepareSubject($class, $method);

$count = (int) $count;
for ($index = 0; $index < $count; $index++) {
    $subject->$method();
}
