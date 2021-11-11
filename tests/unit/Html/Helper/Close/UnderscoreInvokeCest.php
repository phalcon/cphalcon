<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Close;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Close;
use Phalcon\Html\TagFactory;
use UnitTester;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Close
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Close :: __invoke()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlHelperCloseUnderscoreInvoke(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Close - __invoke()');
        $escaper = new Escaper();
        $helper  = new Close($escaper);

        $expected = "</image>";
        $actual   = $helper("image");
        $I->assertEquals($expected, $actual);

        $factory  = new TagFactory($escaper);
        $locator  = $factory->newInstance('close');
        $expected = "</image>";
        $actual   = $locator("image");
        $I->assertEquals($expected, $actual);
    }
}
