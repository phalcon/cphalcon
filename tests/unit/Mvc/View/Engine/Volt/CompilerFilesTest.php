<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalcon.io)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalcon.io so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

use function sprintf;

use const PHP_EOL;

class CompilerFilesTest extends AbstractUnitTestCase
{
    public function setUp(): void
    {
        $compiledFiles = [
            Talon::settings()->supportPath('assets/views/blocks/base.volt.php'),
            Talon::settings()->supportPath('assets/views/blocks/index/login.volt.php'),
            Talon::settings()->supportPath('assets/views/blocks/index/main.volt.php'),
            Talon::settings()->supportPath('assets/views/blocks/partials/header.volt.php'),
        ];
        foreach ($compiledFiles as $fileName) {
            $this->safeDeleteFile($fileName);
        }
    }

    public function tearDown(): void
    {
        $compiledFiles = [
            Talon::settings()->supportPath('assets/views/blocks/base.volt.php'),
            Talon::settings()->supportPath('assets/views/blocks/base.volt%%e%%.php'),
            Talon::settings()->supportPath('assets/views/blocks/index/login.volt.php'),
            Talon::settings()->supportPath('assets/views/blocks/index/main.volt.php'),
            Talon::settings()->supportPath('assets/views/blocks/partials/header.volt.php'),
            Talon::settings()->supportPath('assets/views/extends/children.extends.volt.php'),
            Talon::settings()->supportPath('assets/views/extends/import.volt.php'),
            Talon::settings()->supportPath('assets/views/extends/import2.volt.php'),
            Talon::settings()->supportPath('assets/views/layouts/extends.volt.php'),
            Talon::settings()->supportPath('assets/views/partials/header.volt.php'),
            Talon::settings()->supportPath('assets/views/partials/header2.volt.php'),
            Talon::settings()->supportPath('assets/views/partials/header3.volt.php'),
            Talon::settings()->supportPath('assets/views/partials/footer.volt.php'),
        ];

        foreach ($compiledFiles as $fileName) {
            $this->safeDeleteFile($fileName);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-06-25
     */
    public function testMvcViewEngineVoltCompileBlocks(): void
    {
        $template = '<!DOCTYPE html>' . PHP_EOL
            . '<html lang="en">' . PHP_EOL
            . '<head>' . PHP_EOL
            . '    <meta charset="utf-8" />' . PHP_EOL
            . '    <meta name="viewport" content="width=device-width, initial-scale=1.0" />' . PHP_EOL
            . '</head>' . PHP_EOL
            . '<body>' . PHP_EOL
            . PHP_EOL
            . PHP_EOL
            . PHP_EOL
            . '%s' . PHP_EOL
            . PHP_EOL
            . PHP_EOL
            . '</body>' . PHP_EOL
            . '</html>' . PHP_EOL;

        /**
         * Set up the view and Volt and compile
         */
        $view = new View();
        $view->setViewsDir(
            [
                Talon::settings()->supportPath('assets/views/blocks'),
            ]
        );

        $volt = new Compiler($view);

        /**
         * Login - no header output
         */
        $volt->compileFile(
            Talon::settings()->supportPath('assets/views/blocks/index/login.volt'),
            Talon::settings()->supportPath('assets/views/blocks/index/login.volt.php')
        );

        $file     = Talon::settings()->supportPath('assets/views/blocks/index/login.volt.php');
        $expected = sprintf($template, '<p>This is the login page</p>');
        $this->assertFileContentsEqual($file, $expected);

        /**
         * Main page = header output
         */
        $volt->compileFile(
            Talon::settings()->supportPath('assets/views/blocks/index/main.volt'),
            Talon::settings()->supportPath('assets/views/blocks/index/main.volt.php')
        );

        $file = Talon::settings()->supportPath('assets/views/blocks/index/main.volt.php');

        $expected = sprintf($template, '<p>This is the main page</p>');
        $this->assertFileContentsEqual($file, $expected);
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompileExtendsFile(): void
    {
        $view = new View();
        $view->setViewsDir(Talon::settings()->supportPath('assets/views/'));

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            Talon::settings()->supportPath('assets/views/extends/children.extends.volt'),
            Talon::settings()->supportPath('assets/views/extends/children.extends.volt.php')
        );

        $file     = Talon::settings()->supportPath('assets/views/extends/children.extends.volt.php');
        $contents = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">'
            . '<html lang="en"><html xmlns="http://www.w3.org/1999/xhtml">'
            . '<head><style type="text/css">.important { color: #336699; }</style>'
            . '<title>Index - My Webpage</title></head><body>'
            . '<div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p>'
            . '</div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.'
            . '</div></body>';

        $this->assertFileContentsEqual($file, $contents);
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompileImportFile(): void
    {
        $view = new View();
        $view->setViewsDir(Talon::settings()->supportPath('assets/views/'));

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            Talon::settings()->supportPath('assets/views/extends/import.volt'),
            Talon::settings()->supportPath('assets/views/extends/import.volt.php')
        );

        $file     = Talon::settings()->supportPath('assets/views/extends/import.volt.php');
        $contents = '<div class="header"><h1>This is the header</h1></div>'
            . '<div class="footer"><p>This is the footer</p></div>';
        $this->assertFileContentsEqual($file, $contents);
    }

    /**
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompileImportRecursiveFiles(): void
    {
        $view = new View();
        $view->setViewsDir(Talon::settings()->supportPath('assets/views/'));

        $volt = new Compiler($view);

        //extends
        $volt->compileFile(
            Talon::settings()->supportPath('assets/views/extends/import2.volt'),
            Talon::settings()->supportPath('assets/views/extends/import2.volt.php')
        );

        $file     = Talon::settings()->supportPath('assets/views/extends/import2.volt.php');
        $contents = '<div class="header"><h1>This is the title</h1></div>';
        $this->assertFileContentsEqual($file, $contents);
    }
}
