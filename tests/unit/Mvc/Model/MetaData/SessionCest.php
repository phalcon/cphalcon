<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Metadata\Session;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\SessionCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Session component
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
class SessionCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        $I->haveServiceInDi('modelsMetadata', function () {
            return new Session([
                'prefix' => 'app',
            ]);
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';

        session_start();
    }

    public function _after(UnitTester $I)
    {
        session_destroy();
    }

    public function redis(UnitTester $I)
    {
        $I->wantTo('fetch metadata from session');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            $_SESSION['$PMM$app']["meta-phalcon\\test\\models\\robots-robots"]
        );

        $I->assertEquals(
            $this->data['map-robots'],
            $_SESSION['$PMM$app']["map-phalcon\\test\\models\\robots"]
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
