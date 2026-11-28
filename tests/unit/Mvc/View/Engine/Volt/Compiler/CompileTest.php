<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Engine\Volt\Exceptions\TemplateFileNotFound;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use PHPUnit\Framework\Attributes\DataProvider;

use const PHP_OS;

class CompileTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array{0: bool}>
     */
    public static function provideStat(): array
    {
        return [
            [true],
            [false],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompile(): void
    {
        $viewFile    = Talon::settings()->supportPath('assets/views/compiler/partial.volt');
        $compileFile = $viewFile . '.php';

        $compiler = new Compiler();
        $compiler->compile($viewFile);

        $this->assertFileExists($compileFile);
        $this->assertSame($compileFile, $compiler->getCompiledTemplatePath());

        $this->safeDeleteFile($compileFile);
    }

    /**
     * A closure "path" option is called on each call.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerCompileClosurePath(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-closure/');
        $template = $dir . 'index.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($dir, 0777, true);
        file_put_contents($template, 'Hello');

        $calls    = 0;
        $compiler = new Compiler();
        $compiler->setOption(
            'path',
            function (string $templatePath) use (&$calls): string {
                $calls++;

                return $templatePath . '.php';
            }
        );

        $compiler->compile($template);
        $compiler->compile($template);
        $actual = $compiler->getCompiledTemplatePath();

        $this->safeDeleteDirectory($dir);

        $this->assertSame(2, $calls);
        $this->assertSame($template . '.php', $actual);
    }

    /**
     * The compiled path has the virtual path of the template (the real path
     * in lower case, the separators replaced). The second call gives the
     * same path. The extends mode adds the "e" suffix.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerCompileCompiledPath(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-path/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'Index.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, '{% block content %}Hello{% endblock %}');

        $virtual = str_replace(['/', '\\', ':'], '_', strtolower((string) realpath($template)));

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_']);

        $compiler->compile($template);
        $first = $compiler->getCompiledTemplatePath();

        $compiler->compile($template);
        $second = $compiler->getCompiledTemplatePath();

        $compiler->compile($template, true);
        $extends = $compiler->getCompiledTemplatePath();

        $this->safeDeleteDirectory($dir);

        $this->assertSame($cache . $virtual . '.php', $first);
        $this->assertSame($first, $second);
        $this->assertSame($cache . $virtual . '_e_.php', $extends);
    }

    /**
     * With "stat" false, the extends mode uses the compiled blocks file when
     * it exists. A change of the template does not compile it again.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     *
     * @see    https://github.com/phalcon/cphalcon/issues/17674
     */
    public function testMvcViewEngineVoltCompilerCompileExtendsModeStatFalse(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-extends-stat-false/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'layout.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, '<p>{% block a %}PA{% endblock %}</p>');

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_', 'stat' => false]);

        $first = $compiler->compile($template, true);

        file_put_contents($template, '<p>{% block a %}NEW{% endblock %}</p>');
        touch($template, time() + 10);
        clearstatcache(true);

        $second = $compiler->compile($template, true);

        $this->safeDeleteDirectory($dir);

        $expected = [
            0   => '<p>',
            'a' => [
                [
                    'type'  => 357,
                    'value' => 'PA',
                    'file'  => $template,
                    'line'  => 1,
                ],
            ],
            1   => '</p>',
        ];

        $this->assertSame($expected, $first);
        $this->assertSame($expected, $second);
    }

    /**
     * With "stat" false, a compiled blocks file that does not hold an array
     * is not used. The template is compiled again and the file is replaced.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     *
     * @see    https://github.com/phalcon/cphalcon/issues/17674
     */
    public function testMvcViewEngineVoltCompilerCompileExtendsModeStatFalsePlantedCache(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-extends-stat-false-planted/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'layout.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, '<p>{% block a %}PA{% endblock %}</p>');

        $virtual = str_replace(['/', '\\', ':'], '_', strtolower((string) realpath($template)));
        $path    = $cache . $virtual . '_e_.php';

        file_put_contents($path, 'O:8:"stdClass":0:{}');

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_', 'stat' => false]);

        $actual = $compiler->compile($template, true);
        $stored = unserialize((string) file_get_contents($path), ['allowed_classes' => false]);

        $this->safeDeleteDirectory($dir);

        $expected = [
            0   => '<p>',
            'a' => [
                [
                    'type'  => 357,
                    'value' => 'PA',
                    'file'  => $template,
                    'line'  => 1,
                ],
            ],
            1   => '</p>',
        ];

        $this->assertSame($expected, $actual);
        $this->assertSame($expected, $stored);
    }

    /**
     * With "stat" true, the extends mode uses the compiled blocks file when
     * it is newer than the template.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     *
     * @see    https://github.com/phalcon/cphalcon/issues/17674
     */
    public function testMvcViewEngineVoltCompilerCompileExtendsModeStatTrueCached(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-extends-stat-true-cached/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'layout.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, '<p>{% block a %}PA{% endblock %}</p>');

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_', 'stat' => true]);

        $compiler->compile($template, true);
        $path = $compiler->getCompiledTemplatePath();

        file_put_contents($template, '<p>{% block a %}NEW{% endblock %}</p>');
        clearstatcache(true);
        touch($path, filemtime($template) + 10);
        clearstatcache(true);

        $actual = $compiler->compile($template, true);

        $this->safeDeleteDirectory($dir);

        $expected = [
            0   => '<p>',
            'a' => [
                [
                    'type'  => 357,
                    'value' => 'PA',
                    'file'  => $template,
                    'line'  => 1,
                ],
            ],
            1   => '</p>',
        ];

        $this->assertSame($expected, $actual);
    }

    /**
     * With "stat" true, the extends mode compiles the template again when
     * the compiled blocks file is older than the template.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     *
     * @see    https://github.com/phalcon/cphalcon/issues/17674
     */
    public function testMvcViewEngineVoltCompilerCompileExtendsModeStatTrueStale(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-extends-stat-true-stale/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'layout.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, '<p>{% block a %}PA{% endblock %}</p>');

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_', 'stat' => true]);

        $compiler->compile($template, true);
        $path = $compiler->getCompiledTemplatePath();

        file_put_contents($template, '<p>{% block a %}NEW{% endblock %}</p>');
        clearstatcache(true);
        touch($path, filemtime($template) - 10);
        clearstatcache(true);

        $actual = $compiler->compile($template, true);

        $this->safeDeleteDirectory($dir);

        $expected = [
            0   => '<p>',
            'a' => [
                [
                    'type'  => 357,
                    'value' => 'NEW',
                    'file'  => $template,
                    'line'  => 1,
                ],
            ],
            1   => '</p>',
        ];

        $this->assertSame($expected, $actual);
    }

    /**
     * Two templates extend the same layout. The second template uses the
     * compiled blocks file of the layout and gives the correct output.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     *
     * @see    https://github.com/phalcon/cphalcon/issues/17674
     */
    #[DataProvider('provideStat')]
    public function testMvcViewEngineVoltCompilerCompileExtendsSecondChild(bool $stat): void
    {
        $dir   = Talon::settings()->outputPath('tests/volt-compile-extends-second-child/');
        $cache = $dir . 'cache/';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents(
            $dir . 'layout.volt',
            '<p>{% block a %}PA{% endblock %}|{% block b %}PB{% endblock %}</p>'
        );
        file_put_contents(
            $dir . 'one.volt',
            "{% extends '" . $dir . "layout.volt' %}{% block a %}ONE{% endblock %}"
        );
        file_put_contents(
            $dir . 'two.volt',
            "{% extends '" . $dir . "layout.volt' %}{% block b %}TWO{% endblock %}"
        );

        $compiler = new Compiler();
        $compiler->setOptions(
            [
                'always'    => false,
                'path'      => $cache,
                'separator' => '_',
                'stat'      => $stat,
            ]
        );

        $compiler->compile($dir . 'one.volt');
        $one = file_get_contents($compiler->getCompiledTemplatePath());

        $compiler->compile($dir . 'two.volt');
        $two = file_get_contents($compiler->getCompiledTemplatePath());

        $this->safeDeleteDirectory($dir);

        $this->assertSame('<p>ONE|PB</p>', $one);
        $this->assertSame('<p>PA|TWO</p>', $two);
    }

    /**
     * The compiler keeps the virtual path of a template path. A change of a
     * symbolic link in the path after the first call does not change the
     * compiled path. setOption() clears the kept paths.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerCompileKeepsVirtualPath(): void
    {
        if ('WINNT' === PHP_OS) {
            $this->markTestSkipped('Symbolic links need more rights on Windows');
        }

        $dir   = Talon::settings()->outputPath('tests/volt-compile-keep/');
        $cache = $dir . 'cache/';
        $link  = $dir . 'link';

        if (is_link($link)) {
            unlink($link);
        }

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        mkdir($dir . 'one');
        mkdir($dir . 'two');
        file_put_contents($dir . 'one/index.volt', 'One');
        file_put_contents($dir . 'two/index.volt', 'Two');
        symlink($dir . 'one', $link);

        $one = str_replace(['/', '\\', ':'], '_', strtolower((string) realpath($dir . 'one/index.volt')));
        $two = str_replace(['/', '\\', ':'], '_', strtolower((string) realpath($dir . 'two/index.volt')));

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_']);

        $compiler->compile($link . '/index.volt');
        $first = $compiler->getCompiledTemplatePath();

        unlink($link);
        symlink($dir . 'two', $link);
        clearstatcache(true);

        $compiler->compile($link . '/index.volt');
        $second = $compiler->getCompiledTemplatePath();

        $compiler->setOption('separator', '_');
        $compiler->compile($link . '/index.volt');
        $third = $compiler->getCompiledTemplatePath();

        unlink($link);
        $this->safeDeleteDirectory($dir);

        $this->assertSame($cache . $one . '.php', $first);
        $this->assertSame($first, $second);
        $this->assertSame($cache . $two . '.php', $third);
    }

    /**
     * A template that does not exist at the first call gets its correct
     * compiled path when it exists later.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerCompileMissingTemplate(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-missing/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'index.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_']);

        $exception = '';
        try {
            $compiler->compile($template);
        } catch (TemplateFileNotFound $ex) {
            $exception = $ex::class;
        }

        file_put_contents($template, 'Hello');
        clearstatcache(true);

        $virtual = str_replace(['/', '\\', ':'], '_', strtolower((string) realpath($template)));

        $compiler->compile($template);
        $actual = $compiler->getCompiledTemplatePath();

        $this->safeDeleteDirectory($dir);

        $this->assertSame(TemplateFileNotFound::class, $exception);
        $this->assertSame($cache . $virtual . '.php', $actual);
    }

    /**
     * After setOption() or setOptions(), the next call uses the new
     * separator.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-14
     */
    public function testMvcViewEngineVoltCompilerCompileOptionChange(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-option/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'index.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, 'Hello');

        $real = strtolower((string) realpath($template));

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_']);

        $compiler->compile($template);
        $underscore = $compiler->getCompiledTemplatePath();

        $compiler->setOption('separator', '-');
        $compiler->compile($template);
        $dash = $compiler->getCompiledTemplatePath();

        $compiler->setOptions(['path' => $cache, 'separator' => '+']);
        $compiler->compile($template);
        $plus = $compiler->getCompiledTemplatePath();

        $this->safeDeleteDirectory($dir);

        $this->assertSame($cache . str_replace(['/', '\\', ':'], '_', $real) . '.php', $underscore);
        $this->assertSame($cache . str_replace(['/', '\\', ':'], '-', $real) . '.php', $dash);
        $this->assertSame($cache . str_replace(['/', '\\', ':'], '+', $real) . '.php', $plus);
    }

    /**
     * With "stat" false, a template with a compiled file is not compiled
     * again. The call returns null and the compiled file does not change.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-17
     *
     * @see    https://github.com/phalcon/cphalcon/issues/17674
     */
    public function testMvcViewEngineVoltCompilerCompileStatFalseCompiledFileExists(): void
    {
        $dir      = Talon::settings()->outputPath('tests/volt-compile-stat-false/');
        $cache    = $dir . 'cache/';
        $template = $dir . 'index.volt';

        $this->safeDeleteDirectory($dir);
        mkdir($cache, 0777, true);
        file_put_contents($template, 'Hello');

        $compiler = new Compiler();
        $compiler->setOptions(['path' => $cache, 'separator' => '_', 'stat' => false]);

        $compiler->compile($template);
        $path = $compiler->getCompiledTemplatePath();

        file_put_contents($path, 'CACHED');

        $actual   = $compiler->compile($template);
        $contents = file_get_contents($path);

        $this->safeDeleteDirectory($dir);

        $this->assertNull($actual);
        $this->assertSame('CACHED', $contents);
    }
}
