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

/**
 * Class SetUriCest
 */
class SetUriCest
{
    /**
     * Tests Phalcon\Debug :: setUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugSetUri(UnitTester $I)
    {
        $I->wantToTest('Debug - setUri()');
        $debug = new Debug();
        $uri   = 'https://something.com/test/';

        $expected = sprintf(
            "<link rel='stylesheet' type='text/css' " .
            'href=\'%1$sbower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css\' />' .
            "<link rel='stylesheet' type='text/css' " .
            'href=\'%1$sbower_components/jquery-ui/themes/ui-lightness/theme.css\' />' .
            "<link rel='stylesheet' type='text/css' " .
            'href=\'%1$sthemes/default/style.css\' />',
            $uri
        );

        $debug->setUri($uri);
        $actual = $debug->getCssSources();
        $I->assertEquals($expected, $actual);
    }
}
