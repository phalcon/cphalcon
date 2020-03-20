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

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

use function ob_end_clean;
use function ob_get_contents;
use function ob_start;

use const PHP_EOL;

class AddInlineCssCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        $this->resetDi();
    }

    /**
     * Tests Phalcon\Assets\Manager :: addInlineCss()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerAddInlineCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addInlineCss()');

        $manager = new Manager();

        $css = ".h2:after, .h2:after { content: ''; display: none }";

        $manager->addInlineCss($css);

        $expected = "<style type=\"text/css\">{$css}</style>" . PHP_EOL;

        ob_start();
        $manager->outputInlineCss();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertSame($expected, $actual);
    }
}
