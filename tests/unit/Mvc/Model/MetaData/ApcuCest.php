<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Mvc\Model\Metadata\Apcu;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\ApcuCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Apcu component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Metadata
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ApcuCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        if (!function_exists('apc_fetch')) {
            throw new SkippedTestError(
                'Warning: apc extension is not loaded'
            );
        }

        $I->haveServiceInDi('modelsMetadata', function () {
            return new Apcu([
                'prefix'   => 'app\\',
                'lifetime' => 60
            ]);
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
        apcu_clear_cache();
    }

    public function apc(UnitTester $I)
    {
        $I->wantTo('fetch metadata from apc cache');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertEquals(
            $this->data['meta-robots-robots'],
            apcu_fetch('$PMM$app\meta-phalcon\test\models\robots-robots')
        );

        $I->assertEquals(
            $this->data['map-robots'],
            apcu_fetch('$PMM$app\map-phalcon\test\models\robots')
        );

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }
}
