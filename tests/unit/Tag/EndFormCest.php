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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class EndFormCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: endForm()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function tagEndForm(UnitTester $I)
    {
        $I->wantToTest("Tag - endForm()");
        $expected = '</form>';
        $actual   = Tag::endForm();
        $I->assertEquals($expected, $actual);
    }
}
