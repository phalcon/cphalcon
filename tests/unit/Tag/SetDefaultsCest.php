<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class SetDefaultsCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: setDefaults()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testSetDefaults(UnitTester $I)
    {
        $data = [
            'property1' => 'testVal1',
            'property2' => 'testVal2',
            'property3' => 'testVal3',
        ];

        Tag::setDefaults($data);

        $I->assertTrue(Tag::hasValue('property1'));
        $I->assertTrue(Tag::hasValue('property2'));
        $I->assertTrue(Tag::hasValue('property3'));
        $I->assertFalse(Tag::hasValue('property4'));

        $I->assertEquals('testVal1', Tag::getValue('property1'));
        $I->assertEquals('testVal2', Tag::getValue('property2'));
        $I->assertEquals('testVal3', Tag::getValue('property3'));
    }
}
