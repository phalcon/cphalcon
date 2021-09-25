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

class EndFormCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: endForm()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagEndForm(UnitTester $I)
    {
        $I->wantToTest('Tag - endForm()');
        $expected = '</form>';
        $actual   = Tag::endForm();
        $I->assertEquals($expected, $actual);
    }
}
