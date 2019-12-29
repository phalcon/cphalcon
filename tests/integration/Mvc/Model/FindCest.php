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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Cache;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Migrations\ObjectsMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Objects;

use function outputDir;

/**
 * Class FindCest
 */
class FindCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: find()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFind(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - find()');

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        /**
         * Setup the table
         */
        (new ObjectsMigration())($this->container->get('db'));

        $data = Objects::find();

        $I->assertEquals(1, count($data));

        $record = $data[0];
        $I->assertEquals(1, $record->obj_id);
        $I->assertEquals('random data', $record->obj_name);
    }

    /**
     * Tests Phalcon\Mvc\Model :: find()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFindWithCache(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - find() - with cache');

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $file = outputDir('data-/my/-c/ac/my-cache');
        $I->safeDeleteFile($file);

        /**
         * Setup the table
         */
        (new ObjectsMigration())($this->container->get('db'));

        $options = [
            'defaultSerializer' => 'Json',
            'storageDir'        => outputDir(),
            'lifetime'          => 172800,
            'prefix'            => 'data-',
        ];

        // Models Cache setup
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);
        $adapter           = $adapterFactory->newInstance('stream', $options);

        $this->container->setShared('modelsCache', new Cache($adapter));

        /**
         * Get the records (should cache the resultset)
         */
        $data = Objects::find(
            [
                'cache' => [
                    'key' => 'my-cache',
                ],
            ]
        );

        /**
         * See the file created
         */
        $I->seeFileFound($file);

        $I->assertEquals(1, count($data));

        $record = $data[0];
        $I->assertEquals(1, $record->obj_id);
        $I->assertEquals('random data', $record->obj_name);

        /**
         * Get the models cache
         */
        $modelsCache = $this->container->get('modelsCache');

        $exists = $modelsCache->has('my-cache');
        $I->assertTrue($exists);

        /**
         * Get the data now from the cache
         */
        $data = $modelsCache->get('my-cache');

        $I->assertEquals(1, count($data));

        $record = $data[0];
        $I->assertEquals(1, $record->obj_id);
        $I->assertEquals('random data', $record->obj_name);
    }
}
