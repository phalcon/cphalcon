<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use Phalcon\Di;
use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Proxy\Mvc\Model\Metadata\Xcache;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\XcacheCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Xcache component
 *
 * @copyright (c) 2011-2017 Phalcon Team
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
class XcacheCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        if (!function_exists('xcache_emulation') && !function_exists('xcache_get')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: xcache extension is not loaded'
            );
        }

        $I->haveServiceInDi('modelsMetadata', function () {
            return new Xcache([
                'prefix'   => 'app\\',
                'lifetime' => 60
            ]);
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
        xcache_unset('$PMM$app\\');
    }

    public function xcache(UnitTester $I)
    {
        $I->wantTo('fetch metadata from xcache cache');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            xcache_get('$PMM$app\meta-phalcon\test\models\robots-robots')
        );

        $I->assertEquals(
            $this->data['map-robots'],
            xcache_get('$PMM$app\map-phalcon\test\models\robots')
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
