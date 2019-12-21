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

namespace Phalcon\Test\Unit\Tag\Select;

use Phalcon\Tag\Select;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class SelectFieldCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag\Select :: selectField()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagSelectSelectField(UnitTester $I)
    {
        $I->wantToTest('Tag\Select - selectField()');

        $sSelect = Select::selectField('city', ['Lyon', 'Miramas']);

        $I->assertEquals(
            $sSelect,
            "<select id=\"city\" name=\"city\">\n\t" .
            "<option value=\"0\">Lyon</option>\n\t<option value=\"1\">" .
            "Miramas</option>\n</select>"
        );
    }
}
