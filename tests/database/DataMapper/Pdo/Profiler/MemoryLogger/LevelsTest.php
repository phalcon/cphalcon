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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\MemoryLogger;

use Phalcon\DataMapper\Pdo\Profiler\MemoryLogger;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class LevelsTest extends AbstractDatabaseTestCase
{
    public static function providerLevels(): array
    {
        return [
            ['alert'],
            ['critical'],
            ['debug'],
            ['emergency'],
            ['error'],
            ['info'],
            ['notice'],
            ['warning'],
        ];
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    #[DataProvider('providerLevels')]
    public function testDMPdoProfilerMemoryLoggerLevels(string $level): void
    {
        $logger = new MemoryLogger();

        $logger->{$level}($level . ' message');
        $expected = [$level . ' message'];
        $message  = $logger->getMessages();

        $this->assertEquals($expected, $message);
    }
}
