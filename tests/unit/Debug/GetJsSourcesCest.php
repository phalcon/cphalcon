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
 * Class GetJsSourcesCest
 */
class GetJsSourcesCest
{
    /**
     * Tests Phalcon\Debug :: getJsSources()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugGetJsSources(UnitTester $I)
    {
        $I->wantToTest('Debug - getJsSources()');
        $debug = new Debug();
        $uri   = 'https://assets.phalconphp.com/debug/4.0.x/';

        $expected = sprintf(
            '<script type=\'text/javascript\' src=\'%1$sbower_components/jquery/dist/jquery.min.js\'></script>' .
            '<script type=\'text/javascript\' src=\'%1$sbower_components/jquery-ui/jquery-ui.min.js\'></script>' .
            '<script type=\'text/javascript\' src=\'%1$sbower_components/jquery.scrollTo/jquery.scrollTo.min.js\'></script>' .
            '<script type=\'text/javascript\' src=\'%1$sprettify/prettify.js\'></script>' .
            '<script type=\'text/javascript\' src=\'%1$spretty.js\'></script>',
            $uri
        );

        $actual = $debug->getJsSources();
        $I->assertEquals($expected, $actual);
    }
}
