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

use Phalcon\Assets\Inline;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;
use function ob_end_clean;
use function ob_get_contents;
use function ob_start;
use const PHP_EOL;

class AddInlineCodeByTypeCest
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
     * Tests Phalcon\Assets\Manager :: addInlineCodeByType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerAddInlineCodeByType(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addInlineCodeByType()');

        $manager = new Manager();

        $asset = new Inline('css', 'p {color: #000099}');
        $manager->addInlineCodeByType('css', $asset);

        $expected = "<style>p {color: #000099}</style>" . PHP_EOL;

        ob_start();
        $manager->outputInlineCss();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertSame($expected, $actual);
    }
}
