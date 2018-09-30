<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Metadata\Libmemcached;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\LibmemcachedCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Libmemcached component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class LibmemcachedCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        if (!class_exists('Memcached')) {
            throw new SkippedTestError(
                'Warning: Memcached class does not exist, test skipped'
            );
        }

        $I->haveServiceInDi('modelsMetadata', function () {
            return new Libmemcached([
                'servers' => [
                    [
                        'host'   => TEST_MC_HOST,
                        'port'   => TEST_MC_PORT,
                        'weight' => 1,
                    ]
                ]
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
