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
use Phalcon\Test\Unit\Tag\Helper\TagHelper;
use UnitTester;

class TagSetDefaultCest extends TagHelper
{
    /**
     * Tests setDefault
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2402
     * @author Dmitry Patsura <talk@dmtry.me>
     * @since  2014-05-10
     */
    public function testDisplayValues(UnitTester $I)
    {
        Tag::setDefault('property1', 'testVal1');
        Tag::setDefault('property2', 'testVal2');
        Tag::setDefault('property3', 'testVal3');

        $I->assertTrue(Tag::hasValue('property1'));
        $I->assertTrue(Tag::hasValue('property2'));
        $I->assertTrue(Tag::hasValue('property3'));
        $I->assertFalse(Tag::hasValue('property4'));

        $I->assertEquals('testVal1', Tag::getValue('property1'));
        $I->assertEquals('testVal2', Tag::getValue('property2'));
        $I->assertEquals('testVal3', Tag::getValue('property3'));
    }
}
