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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Asset\Css;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Assets\Fake\TrimFilter;
use Phalcon\Tests\Unit\Assets\Fake\UppercaseFilter;

use function file_get_contents;
use function outputDir;

use const PHP_EOL;

final class OutputCssTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    public function tearDown(): void
    {
        $this->resetDi();
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1198
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-09-15
     */
    public function testAssetsManagerOutputCssFilterChainCustomFilterWithCssmin(): void
    {
        $fileName = $this->getNewFileName('assets_', 'css');
        $fileName = outputDir('tests/assets/' . $fileName);
        $cssFile  = supportDir('assets/assets/1198.css');
        $manager  = new Manager(new TagFactory(new Escaper()));

        $manager->useImplicitOutput(false);

        $css = $manager->collection('css');

        $css
            ->setTargetPath($fileName)
            ->addCss($cssFile)
            ->addFilter(new UppercaseFilter())
            ->addFilter(new TrimFilter())
            ->join(true)
        ;

        $manager->outputCss('css');

        $needle  = 'A{TEXT-DECORATION:NONE;}B{FONT-WEIGHT:BOLD;}';
        $content = file_get_contents($fileName);
        $this->assertStringContainsString(
            $needle,
            $content
        );

        $this->safeDeleteFile($fileName);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssImplicit(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('css/style1.css');
        $manager->addCss('css/style2.css');
        $manager->addAsset(
            new Css('/css/style.css', false)
        );

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        $manager->useImplicitOutput(false);

        $this->assertSame($expected, $manager->outputCss());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputCssNotImplicit(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('css/style1.css');
        $manager->addCss('css/style2.css');
        $manager->addAsset(new Css('/css/style.css', false));

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style1.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style2.css" />' . PHP_EOL
            . '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;

        ob_start();
        $manager->outputCss();
        $actual = ob_get_clean();

        $this->assertSame($expected, $actual);
    }
}
