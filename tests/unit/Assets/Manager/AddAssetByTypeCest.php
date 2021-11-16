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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Exception;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use UnitTester;

/**
 * Class AddAssetByTypeCest
 *
 * @package Phalcon\Tests\Unit\Assets\Manager
 */
class AddAssetByTypeCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addAssetByType()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerAddAssetByType(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addAssetByType()');

        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addAssetByType('css', new Css('/css/style1.css'));
        $manager->addAssetByType('css', new Css('/css/style2.css'));


        $collection = $manager->get('css');
        $expected   = 'css';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
        }

        $I->assertCount(2, $collection);
    }
}
