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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Libmemcached;

use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MetaData\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

use function getOptionsLibmemcached;

class WriteCest
{
    use DiTrait;

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

//    /**
//     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: write()
//     *
//     * @author Phalcon Team <team@phalcon.io>
//     * @since  2018-11-13
//     */
//    public function mvcModelMetadataLibmemcachedWrite(IntegrationTester $I)
//    {
//        $I->wantToTest('Mvc\Model\MetaData\Libmemcached - write()');
//        $I->skipTest('Need implementation');
//    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: write() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataLibmemcachedWriteException(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Libmemcached - write() - exception');

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $I->skipTest('Check this to clear the cache if the key is there');

        $options = getOptionsLibmemcached();

        $options['servers'][0]['port'] = 4000;

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $cache      = new Libmemcached($factory, $options);

        $this->container->setShared('modelsMetadata', $cache);

        $I->expectThrowable(
            new Exception('Failed to store metaData to the cache adapter'),
            function () use ($I) {
                Robots::setup(
                    [
                        'exceptionOnFailedMetaDataSave' => true,
                    ]
                );
                Robots::findFirst(1);
            }
        );

        $I->expectThrowable(
            new \Exception('Failed to store metaData to the cache adapter', 1024),
            function () use ($I) {
                Robots::setup(
                    [
                        'exceptionOnFailedMetaDataSave' => false,
                    ]
                );
                Robots::findFirst(1);
            }
        );
    }
}
