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

namespace Phalcon\Test\Unit\Flash\Direct;

use Phalcon\Flash\Direct;
use UnitTester;

/**
 * Class OutputCest
 */
class OutputCest
{
    /**
     * Tests Phalcon\Flash\Direct :: output()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashDirectOutput(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - output()');

        $flash = new Direct();

        $flash->notice('Hello.');
        $flash->debug('Don\'t worry. This is a just a debug message.');
        $flash->error('Now you should worry. This is an error!');

        $flash->clear();

        ob_start();
        $flash->output(false);
        $output = ob_end_clean();

        $this->assertEquals(
            '<div class="noticeMessage">Hello.</div>
<div class="debugMessage">Don\'t worry. This is a just a debug message.</div>
<div class="errorMessage">Now you should worry. This is an error!</div>' . PHP_EOL,
            $output
        );
    }
}
