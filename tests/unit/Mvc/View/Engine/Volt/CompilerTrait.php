<?php

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt;

/**
 * Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerTrait
 */
trait CompilerTrait
{
    protected function _before()
    {
        foreach ($this->cache as $file) {
            if (file_exists(env('PATH_DATA') . $file)) {
                unlink(env('PATH_DATA') . $file);
            }
        }
    }
}
