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

namespace Phalcon\Test\Integration\Cache\Adapter\Apcu;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use IntegrationTester;

class GetAdapterCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: getAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-14
     */
    public function cacheAdapterApcuGetAdapter(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - getAdapter()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $I->assertNull(
            $adapter->getAdapter()
        );
    }
}
