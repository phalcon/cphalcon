<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Adapter\Config;

use Phalcon\Auth\Adapter\Config\ModelAdapterConfig;
use Phalcon\Auth\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class ModelAdapterConfigTest extends AbstractUnitTestCase
{
    public function testIdColumnDefaultsToId(): void
    {
        $config = new ModelAdapterConfig('App\\Models\\User');

        $this->assertSame('id', $config->getIdColumn());
    }

    public function testStoresAndReturnsCustomIdColumn(): void
    {
        $config = new ModelAdapterConfig('App\\Models\\User', 'user_id');

        $this->assertSame('user_id', $config->getIdColumn());
    }

    public function testStoresAndReturnsModelClass(): void
    {
        $config = new ModelAdapterConfig('App\\Models\\User');

        $this->assertSame('App\\Models\\User', $config->getModel());
    }

    public function testThrowsWhenIdColumnEmpty(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/idColumn/');

        new ModelAdapterConfig('App\\Models\\User', '');
    }

    public function testThrowsWhenModelEmpty(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/model/');

        new ModelAdapterConfig('');
    }
}
