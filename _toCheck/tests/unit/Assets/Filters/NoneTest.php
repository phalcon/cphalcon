<?php

namespace Phalcon\Test\Unit\Assets\Filters;

use Phalcon\Assets\Manager;
use Phalcon\Assets\Filters\None;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Unit\Assets\Helper\TrimFilter;
use Phalcon\Test\Unit\Assets\Helper\UppercaseFilter;

/**
 * \Phalcon\Test\Unit\Assets\Filters\NoneTest
 * Tests the \Phalcon\Assets\Filters\None component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Assets\Filters
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class NoneTest extends UnitTest
{
    /**
     * Tests none filter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-10
     */
    public function testAssetsFilterNone()
    {
        $this->specify(
            "The none filter does not return the correct results",
            function () {
                $cssmin   = new None();
                $actual   = $cssmin->filter(' ');
                $expected = ' ';

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests custom filters
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/1198
     * @author  Volodymyr Kolesnykov <volodymyr@wildwolf.name>
     * @since   2013-09-15
     */
    public function testAssetsFilterChainCustomFilterWithCssmin()
    {
        $this->specify(
            "The chaining a custom filter with cssmin does not return the correct results",
            function () {
                $fileName = $this->tester->getNewFileName('assets_', 'css');

                $assets = new Manager();
                $assets->useImplicitOutput(false);
                $css = $assets->collection('css');

                $css->setTargetPath(PATH_CACHE . $fileName);
                $css->addCss(PATH_DATA . 'assets/1198.css');
                $css->addFilter(new UppercaseFilter());
                $css->addFilter(new TrimFilter());
                $css->join(true);
                $assets->outputCss('css');

                $expected = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
                $actual   = file_get_contents(PATH_CACHE . $fileName);

                $this->tester->cleanFile(PATH_CACHE, $fileName);

                expect($actual)->equals($expected);
            }
        );
    }
}
