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

namespace Phalcon\Test\Unit\Debug;

use Phalcon\Debug;
use UnitTester;
use function sprintf;

/**
 * Class GetCssSourcesCest
 */
class GetCssSourcesCest
{
    /**
     * Tests Phalcon\Debug :: getCssSources()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugGetCssSources(UnitTester $I)
    {
        $I->wantToTest('Debug - getCssSources()');
        $debug = new Debug();
        $uri   = 'https://assets.phalconphp.com/debug/4.0.x/';

        $expected = sprintf(
            "<link rel='stylesheet' type='text/css' " .
            'href=\'%1$sbower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css\' />' .
            "<link rel='stylesheet' type='text/css' " .
            'href=\'%1$sbower_components/jquery-ui/themes/ui-lightness/theme.css\' />' .
            "<link rel='stylesheet' type='text/css' " .
            'href=\'%1$sthemes/default/style.css\' />',
            $uri
        );

        $actual = $debug->getCssSources();
        $I->assertEquals($expected, $actual);
    }
}
