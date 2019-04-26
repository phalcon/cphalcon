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

namespace Phalcon\Test\Unit\Assets\Filters\Jsmin;

use Phalcon\Assets\Exception;
use Phalcon\Assets\Filters\Jsmin;
use UnitTester;

/**
 * Class FilterCest
 *
 * @package Phalcon\Test\Unit\Assets\Filters\Jsmin
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: __construct() - no string exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminConstructNonString(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - no string exception');
        $I->skipTest('Need Phalcon implementation');
        $I->expectThrowable(
            new \TypeError(
                'Argument 1 passed to Phalcon\Assets\Filters\Jsmin::filter() ' .
                'must be of the type string, object given'
            ),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter(new \stdClass());
            }
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: __construct() - unterminated
     * comment
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminConstructUnterminatedComment(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - unterminated comment');
        $I->skipTest('Need Phalcon implementation');
        $I->expectThrowable(
            new Exception('Unterminated comment.'),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('/*');
            }
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: __construct() - unterminated string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminConstructUnterminatedString(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - unterminated string');
        $I->skipTest('Need Phalcon implementation');
        $I->expectThrowable(
            new Exception('Unterminated string literal.'),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('a = "');
            }
        );
    }

    /**
     * Tests Phalcon\Assets\Filters\Jsmin :: __construct() - unterminated regex
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function assetsFiltersJsminConstructUnterminatedRegex(UnitTester $I)
    {
        $I->wantToTest('Assets\Filters\Jsmin - filter() - unterminated regex');
        $I->skipTest('Need Phalcon implementation');
        $I->expectThrowable(
            new Exception('Unterminated Regular Expression literal.'),
            function () {
                $jsmin = new Jsmin();
                $jsmin->filter('b = /[a-z]+');
            }
        );
    }
}
