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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Helpers\TagSetup;
use UnitTester;

class DisplayToCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: displayTo()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagDisplayTo(UnitTester $I)
    {
        $I->wantToTest('Tag - displayTo()');

        //Init Data
        Tag::displayTo('city', 'Miramas');
        Tag::displayTo('country', 'France');
        Tag::displayTo('zipcode', '13140');

        //check if exists
        $I->assertTrue(
            Tag::hasValue('city')
        );
        $I->assertTrue(
            Tag::hasValue('country')
        );
        $I->assertTrue(
            Tag::hasValue('zipcode')
        );
        $I->assertFalse(
            Tag::hasValue('area')
        );

        //Check value
        $I->assertEquals(
            'Miramas',
            Tag::getValue('city')
        );
        $I->assertEquals(
            'France',
            Tag::getValue('country')
        );
        $I->assertEquals(
            '13140',
            Tag::getValue('zipcode')
        );
    }
}
