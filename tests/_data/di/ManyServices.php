<?php
use Phalcon\Di\Injectable;

/**
 * SomeService class
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AService extends Injectable {}
class BService extends Injectable {}
class CService extends Injectable {}
class DService extends Injectable {}
class EService extends Injectable {}
class FService extends Injectable {}
class GService extends Injectable {}
class HService extends Injectable {}
class IService extends Injectable {}
class JService extends Injectable {}
class KService extends Injectable {}
class LService extends Injectable {}
class MService extends Injectable {}
class NService extends Injectable {}
class OService extends Injectable {}

class ExampleService extends Injectable
{
    public function __construct(
        AService $AService,
        BService $BService,
        CService $CService,
        DService $DService,
        EService $EService,
        FService $FService,
        GService $GService,
        HService $HService,
        IService $IService,
        JService $JService,
        KService $KService,
        LService $LService,
        MService $MService,
        NService $NService,
        OService $OService
    )
    {
    }

    public function get(){
        return true;
    }
}