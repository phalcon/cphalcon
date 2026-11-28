<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Benchmarks\Logger;

use Phalcon\Di\Di;
use Phalcon\Logger\Enum;
use Phalcon\Logger\Logger;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class LoggerBench
{
    private const CONTEXT = ['name' => 'phalcon'];

    private const MESSAGE = 'User %name% logged in';

    private LastLineAdapter $adapter;

    private Logger $logger;

    private LastLineAdapter $skippedAdapter;

    private Logger $skippedLogger;

    public function setUp(): void
    {
        Di::reset();

        $this->adapter = new LastLineAdapter();
        $this->logger  = new Logger('bench', ['main' => $this->adapter]);

        $this->skippedAdapter = new LastLineAdapter();
        $this->skippedLogger  = new Logger('skipped', ['main' => $this->skippedAdapter]);
        $this->skippedLogger->setLogLevel(Enum::ERROR);
    }

    /**
     * debug() on a logger with the level ERROR: no line is written.
     */
    public function benchDebugSkipped(): void
    {
        $this->skippedLogger->debug(self::MESSAGE, self::CONTEXT);

        if ('' !== $this->skippedAdapter->last) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $this->skippedAdapter->last));
        }
    }

    /**
     * info() with one placeholder, formatted with the default line
     * formatter (date, level, message).
     */
    public function benchInfo(): void
    {
        $this->logger->info(self::MESSAGE, self::CONTEXT);

        if (!str_ends_with($this->adapter->last, 'User phalcon logged in')) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $this->adapter->last));
        }
    }
}
