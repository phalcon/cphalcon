<?php

namespace Phalcon\Test\Unit\Mvc\Model\Metadata;

use Phalcon\Di;
use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Proxy\Mvc\Model\Metadata\Redis;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\RedisCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Redis component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RedisCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        if (!extension_loaded('redis')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: redis extension is not loaded'
            );
        }

        $I->haveServiceInDi('modelsMetadata', function() {
            return new Redis([
                'host' => TEST_RS_HOST,
                'port' => TEST_RS_PORT
            ]);
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
    }

    public function redis(UnitTester $I)
    {
        $I->wantTo('fetch metadata from redis database');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals($this->data['meta-robots-robots'], $md->read("meta-phalcon\\test\\models\\robots-robots"));
        $I->assertEquals($this->data['map-robots'], $md->read("map-phalcon\\test\\models\\robots"));

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
