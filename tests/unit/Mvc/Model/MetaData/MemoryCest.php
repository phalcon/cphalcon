<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData;

use UnitTester;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Robotto;
use Phalcon\Mvc\Model\Metadata\Memory;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Metadata\MemoryCest
 * Tests the \Phalcon\Mvc\Model\Metadata\Memory component
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
class MemoryCest
{
    private $data;

    public function _before(UnitTester $I)
    {
        $I->haveServiceInDi('modelsMetadata', function () {
            return new Memory;
        }, true);

        $this->data = require PATH_FIXTURES . 'metadata/robots.php';
    }

    public function redis(UnitTester $I)
    {
        $I->wantTo('fetch metadata from memory');

        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $I->grabServiceFromDi('modelsMetadata');

        $md->reset();
        $I->assertTrue($md->isEmpty());

        Robots::findFirst();

        $I->assertFalse($md->isEmpty());

        $md->reset();
        $I->assertTrue($md->isEmpty());
    }

    public function testMetadataManual(UnitTester $I)
    {
        /** @var \Phalcon\Mvc\Model\MetaDataInterface $metaData */
        $metaData = $I->grabServiceFromDi('modelsMetadata');

        $di = $I->getApplication()->getDI();

        $robotto = new Robotto($di);

        //Robots
        $pAttributes = array(
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year'
        );

        $attributes = $metaData->getAttributes($robotto);
        $I->assertEquals($attributes, $pAttributes);

        $ppkAttributes = array(
            0 => 'id'
        );

        $pkAttributes = $metaData->getPrimaryKeyAttributes($robotto);
        $I->assertEquals($ppkAttributes, $pkAttributes);

        $pnpkAttributes = array(
            0 => 'name',
            1 => 'type',
            2 => 'year'
        );

        $npkAttributes = $metaData->getNonPrimaryKeyAttributes($robotto);
        $I->assertEquals($pnpkAttributes, $npkAttributes);

        $I->assertEquals($metaData->getIdentityField($robotto), 'id');
    }
}
