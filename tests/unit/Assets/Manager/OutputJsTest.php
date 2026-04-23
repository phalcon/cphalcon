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

use Phalcon\Assets\Asset\Js;
use Phalcon\Assets\Filters\JsMin;
use Phalcon\Assets\Filters\None;
use Phalcon\Assets\Manager;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function ob_get_clean;
use function ob_start;
use function outputDir;
use function sprintf;
use function supportDir;
use function uniqid;

use const PHP_EOL;

final class OutputJsTest extends AbstractUnitTestCase
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsBasic(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->useImplicitOutput(false);

        $manager->collection('js')
                ->addJs(supportDir('assets/assets/jquery.js'), false, false)
                ->setTargetPath(outputDir('tests/assets/combined.js'))
                ->setTargetUri('production/combined.js')
        ;

        $expected = sprintf(
            '<script type="application/javascript" src="%s"></script>%s',
            supportDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $this->assertSame($expected, $manager->outputJs('js'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsDisabledJoin(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->useImplicitOutput(false);

        $manager->collection('js')
                ->addJs(supportDir('assets/assets/jquery.js'), false, false)
                ->setTargetPath(outputDir('tests/assets/combined.js'))
                ->setTargetUri('production/combined.js')
                ->join(false)
        ;

        $expected = sprintf(
            '<script type="application/javascript" src="%s"></script>%s',
            supportDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $this->assertSame($expected, $manager->outputJs('js'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsEnabledJoin(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->useImplicitOutput(false);

        $manager->collection('js')
                ->addJs(supportDir('assets/assets/jquery.js'), false, false)
                ->setTargetPath(outputDir('tests/assets/combined.js'))
                ->setTargetUri('production/combined.js')
                ->join(true)
        ;

        $expected = sprintf(
            '<script type="application/javascript" src="%s"></script>%s',
            supportDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $this->assertSame($expected, $manager->outputJs('js'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsImplicit(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addJs('js/script1.js');
        $manager->addJs('js/script2.js');

        $manager->addAsset(new Js('/js/script3.js', false));
        $manager->useImplicitOutput(false);

        $expected = '<script type="application/javascript" src="/js/script1.js"></script>' . PHP_EOL
            . '<script type="application/javascript" src="/js/script2.js"></script>' . PHP_EOL
            . '<script type="application/javascript" src="/js/script3.js"></script>' . PHP_EOL;

        $this->assertSame($expected, $manager->outputJs());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsJoinAndFilter(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $manager = new Manager(new TagFactory(new Escaper()));
        $jsFile  = supportDir('assets/assets/jquery.js');

        $manager->useImplicitOutput(false);

        $manager->collection('js')
                ->addJs($jsFile, false, false)
                ->setTargetPath(outputDir('tests/assets/combined.js'))
                ->setTargetUri('production/combined.js')
                ->join(false)
                ->addFilter(new None())
        ;

        $expected = sprintf(
            '<script type="application/javascript" src="%s"></script>%s',
            supportDir('assets/assets/jquery.js'),
            PHP_EOL
        );

        $this->assertSame($expected, $manager->outputJs('js'));
    }

    /**
     * @author Paul Scarrone <paul@savvysoftworks.com>
     * @since  2017-06-20
     */
    public function testAssetsManagerOutputJsMixedResources(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->useImplicitOutput(false);
        $manager
            ->collection('header')
            ->setPrefix('http:://cdn.example.com/')
            ->setIsLocal(false)
            ->addJs('js/script1.js')
            ->addJs('js/script2.js')
            ->addCss('css/styles1.css')
            ->addCss('css/styles2.css')
        ;

        $expectedJS = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<script type="application/javascript" '
            . 'src="http:://cdn.example.com/js/script1.js"></script>',
            '<script type="application/javascript" '
            . 'src="http:://cdn.example.com/js/script2.js"></script>'
        );

        $this->assertSame($expectedJS, $manager->outputJs('header'));

        $expectedCSS = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<link rel="stylesheet" type="text/css" ' .
            'href="http:://cdn.example.com/css/styles1.css" />',
            '<link rel="stylesheet" type="text/css" ' .
            'href="http:://cdn.example.com/css/styles2.css" />'
        );

        $this->assertSame($expectedCSS, $manager->outputCss('header'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerOutputJsNotImplicit(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addJs('js/script1.js');
        $manager->addJs('js/script2.js');

        $manager->addAsset(
            new Js(
                '/js/script3.js',
                false
            )
        );

        $expected = '<script type="application/javascript" src="/js/script1.js"></script>' . PHP_EOL .
            '<script type="application/javascript" src="/js/script2.js"></script>' . PHP_EOL .
            '<script type="application/javascript" src="/js/script3.js"></script>' . PHP_EOL;

        ob_start();
        $manager->outputJs();
        $actual = ob_get_clean();

        $this->assertSame($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1532
     * @author Phalcon Team <team@phalcon.io>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2013-10-25
     */
    public function testAssetsManagerOutputJsTargetLocal(): void
    {
        $file   = uniqid() . '.js';
        $jsFile = supportDir('assets/assets/jquery.js');

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->useImplicitOutput(false);

        $manager->collection('js')
                ->addJs($jsFile)
                ->join(true)
                ->addFilter(new JsMin())
                ->setTargetPath(outputDir("tests/assets/{$file}"))
                ->setTargetIsLocal(false)
                ->setPrefix('//phalcon.io/')
                ->setTargetUri('js/jquery.js')
        ;

        $expected = '<script type="application/javascript" '
            . 'src="//phalcon.io/js/jquery.js"></script>' . PHP_EOL;
        $actual   = $manager->outputJs('js');
        $this->assertSame($expected, $actual);

        $this->assertFileExists(outputDir("tests/assets/$file"));
        $this->safeDeleteFile(outputDir("tests/assets/$file"));
    }
}
