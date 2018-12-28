<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class AddJsCest
 */
class AddJsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addJs()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerAddJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addJs()');
        $assets = new Manager();

        $assets->addJs('/js/jquery.js');
        $assets->addJs('/js/jquery-ui.js');

        $collection = $assets->get('js');

        $number   = 0;
        $expected = 'js';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $I->assertEquals($expected, $actual);
            $number++;
        }

        $expected = 2;
        $actual   = $number;
        $I->assertEquals($expected, $actual);
    }
}
