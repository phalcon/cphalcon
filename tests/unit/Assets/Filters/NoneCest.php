<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Filters;

use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Test\Fixtures\Assets\TrimFilter;
use Phalcon\Test\Fixtures\Assets\UppercaseFilter;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;
use function dataFolder;

class NoneCest
{
    use DiTrait;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * Tests custom filters
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/1198
     * @author  Volodymyr Kolesnykov <volodymyr@wildwolf.name>
     * @since   2013-09-15
     */
    public function testAssetsFilterChainCustomFilterWithCssmin(UnitTester $I)
    {
        $fileName = $I->getNewFileName('assets_', 'css');
        $assets   = new Manager();
        $assets->useImplicitOutput(false);
        $css     = $assets->collection('css');
        $cssFile = dataFolder('assets/assets/1198.css');

        $css->setTargetPath(cacheFolder($fileName));
        $css->addCss($cssFile);
        $css->addFilter(new UppercaseFilter());
        $css->addFilter(new TrimFilter());
        $css->join(true);
        $assets->outputCss('css');

        $expected = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
        $actual   = file_get_contents(cacheFolder($fileName));

        $I->safeDeleteFile(cacheFolder($fileName));

        $I->assertEquals($expected, $actual);
    }
}
