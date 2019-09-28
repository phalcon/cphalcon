<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use Codeception\Example;

/**
 * Class CacheCest
 */
class CacheCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: cache()
     *
     * @dataProvider getValidSerializers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-27
     */
    public function mvcModelQueryCache(IntegrationTester $I, Example $serializer)
    {
        $I->wantToTest('Mvc\Model\Query - cache() - '. $serializer[0]);

        $di = $this->getDi();

        // services: modelsCache
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);

        $options = [
            'defaultSerializer' =>  $serializer[0],
            'lifetime'          => 30,
            'storageDir'        => cacheDir('mvcModelQueryCache'),
        ];

        $adapter = $adapterFactory->newInstance('stream', $options);
        $cache   = new Cache($adapter);
        $di->set('modelsCache', $cache);

        $cacheKey         = 'uniqkey' . $serializer[0];
        $options['cache'] = [
            'key'      => $cacheKey,
            'lifetime' => 50,
        ];

        $result = Robots::find($options);

        $numberOfRobots = $result->count();

        // Count should use cache
        $robotscount = Robots::count(
            [
                'cache' => [
                    'key' => $cacheKey,
                ],
            ]
        );
        $I->assertEquals($numberOfRobots, $robotscount, "Count() using cache"); // Test count against cache

        // Create a temporary robot to test if the count is cached or fresh
        $newrobot = new Robots();
        $newrobot->name     = 'Not cached robot';
        $newrobot->type     = 'notcached';
        $newrobot->year     = 2014;
        $newrobot->datetime = '2015-03-05 04:16:17';
        $newrobot->text     = 'Not cached robot';

        $newrobot->create();

        $result = Robots::find($options);
        $I->assertEquals($numberOfRobots, $result->count());

        // Delete the temp robot
        Robots::findFirst("type = 'notcached'")->delete();

        // Test delete robot isn't affecting cache
        $result = Robots::find($options);
        $I->assertNotFalse($result);
        $I->assertEquals($numberOfRobots, $result->count());

        $cache->delete($cacheKey);
    }

    private function getValidSerializers(): array
    {
        return [
            [
                'Igbinary',
            ],
            [
                'Msgpack',
            ],
            [
                'Php',
            ]
        ];
    }
}
