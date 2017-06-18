<?php

namespace Phalcon\Test\Unit5x\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Metadata\Memcache;

/**
 * Phalcon\Test\Unit5x\Mvc\Model\Metadata\MemcacheCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Memcache component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit5x\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MemcacheCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        if (!class_exists('Memcache')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: Memcache class does not exist, test skipped'
            );
        }

        $I->haveServiceInDi('modelsMetadata', function () {
            return new Memcache([
                'host' => env('TEST_MC_HOST', '127.0.0.1'),
                'port' => env('TEST_MC_PORT', 11211),
            ]);
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
    }

    public function memcached(UnitTester $I)
    {
        $I->wantTo('fetch metadata from memcached cache');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            $md->read("meta-phalcon\\test\\models\\robots-robots")
        );
        $I->assertEquals(
            $this->data['map-robots'],
            $md->read("map-phalcon\\test\\models\\robots")
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
