<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug;

use Phalcon\Debug;
use UnitTester;
use function sprintf;

class GetCssSourcesCest
{
    /**
     * Tests Phalcon\Debug :: getCssSources()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function debugGetCssSources(UnitTester $I)
    {
        $I->wantToTest('Debug - getCssSources()');
        $debug = new Debug();
        $uri   = 'https://assets.phalcon.io/debug/4.0.x/';

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
