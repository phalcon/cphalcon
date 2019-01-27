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

use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

/**
 * Class SelectCest
 */
class SelectCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: select()
     *
     * @param UnitTester $I
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-01-27
     */
    public function tagSelect(UnitTester $I)
    {
        $I->wantToTest('Tag - select()');
        
        $this->testFieldParameter(
            $I,
            'select',
            [
                'potato',
                [
                    'Phalcon',
                    'PHP'
                ]
            ],
            "<select id=\"potato\" name=\"potato\">\n\t<option value=\"0\">Phalcon</option>\n\t<option value=\"1\">PHP</option>\n</select"
        );
    }

    /**
     * Tests Phalcon\Tag :: select() with no options
     *
     * @param UnitTester $I
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-01-27
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13352
     */
    public function tagSelectWithNoOptions(UnitTester $I)
    {
        $I->wantToTest('Tag - select() with no options');

        $this->testFieldParameter($I, 'select', [
            'potato',
        ], "<select id=\"potato\" name=\"potato\">\n</select");
    }
}
