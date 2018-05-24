<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerFilesTest
 *
 * Test VOLT template engine
 *
 * @package Phalcon\Test\Unit\Mvc\View\Engine\Volt
 */
class CompilerFilesTest extends UnitTest
{
    /**
     * @var Compiler
     */
    protected $volt;

    /**
     * executed before each test
     */
    protected function _before()
    {
        $this->volt = new Compiler();

        /**
         * @todo this function has to be deleted after move all of integration tests to integration folder
         */
        chdir(PROJECT_PATH);
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Tests Compiler::compileFile test case to compile files
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldCompileFiles()
    {
        $this->specify(
            "Volt can't compile files properly",
            function ($params, $expected) {
                $this->volt->compileFile($params['compileFiles'][0], $params['compileFiles'][1]);

                expect(file_get_contents($params['contentPath']))->equals($expected);

                $this->silentRemoveFiles($params['removeFiles']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/view/engine/volt/compiler_files_test/volt_compiler_file.php'
            ]
        );
    }

    /**
     * Tests Compiler::compileFile test case to compile extended files
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-29
     */
    public function shouldCompileFileExtendsMultiple()
    {
        $this->volt->compile('tests/_data/views/templates/c.volt');

        expect(trim(file_get_contents(PATH_DATA . 'views/templates/c.volt.php')))->equals("[A[###[B]###]]");

        $this->silentRemoveFiles([
            PATH_DATA . 'views/templates/a.volt%%e%%.php',
            PATH_DATA . 'views/templates/b.volt%%e%%.php',
            PATH_DATA . 'views/templates/c.volt.php',
        ]);
    }

    /**
     * Tests Compiler::compileFile test case to compile extended files with blocks
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-29
     */
    public function shouldCompileFileExtendsWithBlocks()
    {
        $data = include_once PATH_FIXTURES . 'mvc/view/engine/volt/compiler_files_test/volt_compiler_extends_block.php';
        $this->volt->compile($data['compileFile']);

        expect(file_get_contents($data['contentPath']))->equals($data['expected']);

        $this->silentRemoveFiles($data['removeFiles']);
    }

    /**
     * Tests Compiler::compileFile test case to compile extended files with blocks and two-way blocks
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-29
     */
    public function shouldCompileFileExtendsWithBlockAndTwoWayBlocks()
    {
        $this->specify(
            "Volt can't compile files correctly",
            function ($params, $expected) {
                $this->volt->compile($params['compileFile']);

                expect(file_get_contents($params['contentPath']))->equals($expected);

                $this->silentRemoveFiles($params['removeFiles']);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/view/engine/volt/compiler_files_test/volt_compile_file_extends_multiple.php'
            ]
        );
    }
}
