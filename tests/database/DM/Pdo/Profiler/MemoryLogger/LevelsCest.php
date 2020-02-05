<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Profiler\MemoryLogger;

use Codeception\Example;
use DatabaseTester;
use Phalcon\DM\Pdo\Profiler\MemoryLogger;

class LevelsCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Profiler\MemoryLogger ::
     *
     * @dataProvider getExamples
     * @since        2020-01-25
     */
    public function dMPdoProfilerMemoryLoggerLevels(DatabaseTester $I, Example $example)
    {
        $I->wantToTest('DM\Pdo\Profiler\MemoryLogger - ' . $example[0]);

        $logger = new MemoryLogger();

        $logger->{$example[0]}($example[0] . ' message');
        $expected = [$example[0] . ' message'];
        $message  = $logger->getMessages();

        $I->assertEquals($expected, $message);
    }

    private function getExamples(): array
    {
        return [
            [
                'alert',
            ],
            [
                'critical',
            ],
            [
                'debug',
            ],
            [
                'emergency',
            ],
            [
                'error',
            ],
            [
                'info',
            ],
            [
                'notice',
            ],
            [
                'warning',
            ],
        ];
    }
}
