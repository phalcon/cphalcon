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

namespace Phalcon\Test\Integration\Storage\Adapter\Apcu;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use IntegrationTester;

class GetSetDefaultSerializerCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu ::
     * getDefaultSerializer()/setDefaultSerializer()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-13
     */
    public function storageAdapterApcuGetKeys(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - getDefaultSerializer()/setDefaultSerializer()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $I->assertEquals('Php', $adapter->getDefaultSerializer());

        $adapter->setDefaultSerializer('Base64');
        $I->assertEquals('Base64', $adapter->getDefaultSerializer());
    }
}
