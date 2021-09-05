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

namespace Phalcon\Test\Unit\Support\Debug;

use Phalcon\Support\Debug;
use UnitTester;

use function sprintf;

class GetJsSourcesCest
{
    /**
     * Tests Phalcon\Debug :: getJsSources()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugGetJsSources(UnitTester $I)
    {
        $I->wantToTest('Debug - getJsSources()');
        $debug = new Debug();
        $uri   = 'https://assets.phalcon.io/debug/5.0.x/';

        $expected = sprintf(
            '<script type=\'text/javascript\' ' .
            'src=\'%1$sassets/jquery/dist/jquery.min.js\'></script>' .
            '<script type=\'text/javascript\' ' .
            'src=\'%1$sassets/jquery-ui/jquery-ui.min.js\'></script>' .
            '<script type=\'text/javascript\' ' .
            'src=\'%1$sassets/jquery.scrollTo/jquery.scrollTo.min.js\'></script>' .
            '<script type=\'text/javascript\' src=\'%1$sprettify/prettify.js\'></script>' .
            '<script type=\'text/javascript\' src=\'%1$spretty.js\'></script>',
            $uri
        );

        $actual = $debug->getJsSources();
        $I->assertEquals($expected, $actual);
    }
}
