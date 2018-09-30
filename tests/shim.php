<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

if (!class_exists('\PHPUnit\Framework\TestCase') and class_exists('PHPUnit_Framework_TestCase')) {
    /** @noinspection PhpIgnoredClassAliasDeclaration */
    class_alias('PHPUnit_Framework_TestCase', '\PHPUnit\Framework\TestCase');
}

if (!class_exists('\PHPUnit\TextUI\ResultPrinter') and class_exists('PHPUnit_TextUI_ResultPrinter')) {
    /** @noinspection PhpIgnoredClassAliasDeclaration */
    class_alias('PHPUnit_TextUI_ResultPrinter', '\PHPUnit\TextUI\ResultPrinter');
}

if (!class_exists('\PHPUnit\Framewor\Exception') and class_exists('PHPUnit_Framework_Exception')) {
    /** @noinspection PhpIgnoredClassAliasDeclaration */
    class_alias('PHPUnit_Framework_Exception', '\PHPUnit\Framewor\Exception');
}

if (!class_exists('\PHPUnit\TextUI\Command') and class_exists('PHPUnit_TextUI_Command')) {
    /** @noinspection PhpIgnoredClassAliasDeclaration */
    class_alias('PHPUnit_TextUI_Command', '\PHPUnit\TextUI\Command');
}

if (!class_exists('\PHPUnit\Framework\SkippedTestError') and class_exists('PHPUnit_Framework_SkippedTestError')) {
    /** @noinspection PhpIgnoredClassAliasDeclaration */
    class_alias('PHPUnit_Framework_SkippedTestError', '\PHPUnit\Framework\SkippedTestError');
}

if (!class_exists('\PHPUnit\TextUI\Command') and class_exists('PHPUnit_TextUI_Command')) {
    /** @noinspection PhpIgnoredClassAliasDeclaration */
    class_alias('PHPUnit_TextUI_Command', '\PHPUnit\TextUI\Command');
}

if (!function_exists('env')) {
    function env($key, $default = null)
    {
        if (defined($key)) {
            return constant($key);
        }

        return getenv($key) ?: $default;
    }
}
