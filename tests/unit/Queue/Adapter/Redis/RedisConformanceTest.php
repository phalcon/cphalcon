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

namespace Phalcon\Tests\Unit\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Adapter\Redis\RedisConnectionFactory;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Queue\AbstractContextConformanceTestCase;
use Throwable;

use function array_merge;
use function extension_loaded;
use function uniqid;

final class RedisConformanceTest extends AbstractContextConformanceTestCase
{
    private array $options = [];

    protected function setUp(): void
    {
        parent::setUp();

        if (!extension_loaded('redis')) {
            $this->markTestSkipped('The redis extension is not loaded');
        }

        $this->options = array_merge(
            Talon::settings()->getServiceOptions('redis'),
            ['prefix' => 'phalcon_queue_test_' . uniqid('', true) . ':']
        );

        try {
            $this->createContext();
        } catch (Throwable $exception) {
            $this->markTestSkipped('Redis server is not available: ' . $exception->getMessage());
        }
    }

    protected function createContext(): ContextInterface
    {
        return (new RedisConnectionFactory($this->options))
            ->createContext();
    }
}
